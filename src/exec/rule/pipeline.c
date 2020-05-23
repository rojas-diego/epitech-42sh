/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule pipeline
*/

#include "proto/exec/rule/debug.h"

#include "proto/job/create.h"
#include "proto/job/destroy.h"
#include "proto/job/launch.h"
#include "proto/exec/rule/command.h"
#include "proto/exec/rule/pipeline.h"

#include "hasher/get_data.h"
#include "types/builtins.h"

_Bool job_process_is_last_is_builtin(struct sh *shell, struct job_s *job)
{
    struct process_s *process = job->first_process;

    for (; process->next; process = process->next);
    if (*((builtin_handler *) hasher_get_data(
        shell->builtin, process->argv[0]))
    ) {
        return (true);
    }
    return (false);
}

static void exec_rule_pipeline_launch_job(struct sh *shell, struct job_s *job)
{
    builtin_handler *builtin = (builtin_handler *) hasher_get_data(
        shell->builtin, job->first_process->argv[0]
    );

    //exec_replace_alias(shell, job);

    if (!job->first_process->next && builtin && *builtin) {
        (*builtin)(shell, (const char * const *) job->first_process->argv);
    } else {
        shell->job = job;
        job_launch(shell, job, true);
    }
}

int exec_rule_pipeline(
    struct sh *shell,
    struct expr_pipeline_s *rule
)
{
    struct job_s *job = job_create(0);
    int ret = 0;

    exec_rule_debug(shell, "pipeline", true);
    for (; rule; rule = rule->pipeline) {
        ret = exec_rule_command(shell, rule->command, job);
        if (ret) {
            job_destroy(job);
            return (ret);
        }
    }
    exec_rule_debug(shell, "job_launch", true);
    exec_rule_job_display(shell, job);
    exec_rule_pipeline_launch_job(shell, job);
    exec_rule_debug(shell, "job_launch", false);
    exec_rule_debug(shell, "pipeline", false);
    return (0);
}
