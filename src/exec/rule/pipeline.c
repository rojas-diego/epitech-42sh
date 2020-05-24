/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule pipeline
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "proto/exec/rule/debug.h"
#include "types/exec/rule.h"

#include "proto/job/create.h"
#include "proto/job/destroy.h"
#include "proto/job/launch.h"
#include "proto/exec/rule/command.h"
#include "proto/exec/rule/subshell.h"
#include "proto/exec/rule/pipeline.h"
#include "parser_toolbox/string_split.h"
#include "parser_toolbox/argv_length.h"
#include "hasher/get_data.h"
#include "types/builtins.h"

void follow_alias(
    struct process_s **process,
    struct process_s **save,
    char *data
);

char *builtin_alias_replace_recursively(
    struct hasher_s *alias,
    char *key,
    int depth
)
{
    char *data = (char *) hasher_get_data(alias, key);

    if (data && depth < 100) {
        return (builtin_alias_replace_recursively(alias, data, depth + 1));
    } else {
        if (depth == 0) {
            return (key);
        }
        if (depth >= 100) {
            dprintf(2, "Alias loop.\n");
            return ((char *) -1);
        }
        data = strdup(key);
        return (data);
    }
}

void replace_add_data(struct process_s *process, char *data)
{
    char **strs = ptb_string_split(data, " ");
    size_t length = ptb_argv_length((const char * const *) strs)
        + ptb_argv_length((const char * const *) process->argv) + 1;
    char **new = calloc(length + 1, sizeof(char *));
    char **old = process->argv;

    process->argv = new;
    process->argc = 0;
    for (size_t i = 0; strs[i]; ++i) {
        process->argv[process->argc++] = strs[i];
    }
    for (size_t i = 1; old[i]; ++i) {
        process->argv[process->argc++] = old[i];
    }
}

static int exec_replace_alias(struct sh *shell, struct job_s *job)
{
    struct process_s *process = job->first_process;
    char *data = NULL;
    struct process_s *save = process;

    for (; process;) {
        if (process->subshell) {
            process = process->next;
            continue;
        }
        data = builtin_alias_replace_recursively(
            shell->alias, process->argv[0], 0
        );
        if (!data)
            return (EXEC_RULE_ALLOCATION_FAIL);
        if (data == (char *) -1)
            return (EXEC_RULE_ALIAS_LOOP);
        follow_alias(&process, &save, data);
    }
    return (EXEC_RULE_SUCCESS);
}

static int exec_rule_pipeline_launch_job(
    struct sh *shell,
    struct job_s *job,
    bool foreground
)
{
    if (exec_replace_alias(shell, job)) {
        return (EXEC_RULE_ALLOCATION_FAIL);
    }
    shell->job = job;
    job->foreground = foreground;
    job_launch(shell, job);
    return (EXEC_RULE_SUCCESS);
}

int exec_rule_pipeline(
    struct sh *shell,
    struct expr_pipeline_s *rule,
    bool foreground
)
{
    struct job_s *job = job_create(0);
    int ret = 0;

    exec_rule_debug(shell, "pipeline", true);
    for (; rule; rule = rule->pipeline) {
        ret = rule->command ? exec_rule_command(shell, rule->command, job)
            : exec_rule_subshell(shell, rule->subshell, job);
        if (ret) {
            job_destroy(job);
            return (ret);
        }
    }
    exec_rule_debug(shell, "job_launch", true);
    exec_rule_job_display(shell, job);
    if (exec_rule_pipeline_launch_job(shell, job, foreground)) {
        return (EXEC_RULE_ALLOCATION_FAIL);
    }
    exec_rule_debug(shell, "job_launch", false);
    exec_rule_debug(shell, "pipeline", false);
    return (shell->last_status);
}
