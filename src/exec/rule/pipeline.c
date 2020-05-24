/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule pipeline
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "proto/exec/rule/debug.h"
#include "types/exec/rule.h"

#include "proto/job/create.h"
#include "proto/job/destroy.h"
#include "proto/job/launch.h"
#include "proto/exec/rule/command.h"
#include "proto/exec/rule/subshell.h"
#include "proto/exec/rule/pipeline.h"

#include "hasher/get_data.h"
#include "types/builtins.h"

static _Bool job_process_is_last_is_builtin(struct sh *shell, struct job_s *job)
{
    struct process_s *process = job->first_process;
    builtin_handler *func = NULL;

    for (; process->next; process = process->next);
    func = (builtin_handler *) hasher_get_data(
        shell->builtin, process->argv[0]
    );
    if (func && *func) {
        return (true);
    }
    return (false);
}

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

static int exec_replace_alias(struct sh *shell, struct job_s *job)
{
    struct process_s *process = job->first_process;
    char *data = NULL;

    for (; process; process = process->next) {
        data = builtin_alias_replace_recursively(
            shell->alias, process->argv[0], 0
        );
        if (!data) {
            return (EXEC_RULE_ALLOCATION_FAIL);
        }
        if (data == (char *) -1) {
            return (EXEC_RULE_ALIAS_LOOP);
        }
        if (data != process->argv[0]) {
            free(process->argv[0]);
            process->argv[0] = data;
        }
    }
    return (EXEC_RULE_SUCCESS);
}

static int exec_rule_pipeline_launch_job(
    struct sh *shell,
    struct job_s *job,
    bool foreground
)
{
    builtin_handler *builtin = NULL;

    if (exec_replace_alias(shell, job)) {
        return (EXEC_RULE_ALLOCATION_FAIL);
    }
    builtin = (builtin_handler *) hasher_get_data(
        shell->builtin, job->first_process->argv[0]
    );
    if (!job->first_process->next && builtin && *builtin) {
        (*builtin)(shell, (const char * const *) job->first_process->argv);
    } else {
        shell->job = job;
        if (job_process_is_last_is_builtin(shell, job)) {
        }
        job->foreground = foreground;
        job_launch(shell, job);
    }
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
