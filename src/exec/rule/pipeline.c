/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule pipeline
*/

#include "proto/exec/rule/debug.h"

#include "proto/job/create.h"
#include "proto/job/launch.h"
#include "proto/exec/rule/command.h"
#include "proto/exec/rule/pipeline.h"

#include <stdio.h>

static void job_display(struct job_s *job)
{
    dprintf(2, "/ Job\n");
    for (struct process_s *s = job->first_process; s; s = s->next) {
        dprintf(2, "PROC: ");
        for (size_t i = 0; i < s->argc; ++i) {
            dprintf(2, "%s ", s->argv[i]);
        }
        dprintf(2, "\n");
    }
    dprintf(2, "\\ Job\n");
}

int exec_rule_pipeline(
    struct sh *shell,
    struct expr_pipeline_s *rule
)
{
    struct job_s *job = job_create(0);

    exec_rule_debug(shell, "pipeline", true);
    for (; rule; rule = rule->pipeline) {
        if (rule->command) {
            exec_rule_command(shell, rule->command, job);
        }
    }
    exec_rule_debug(shell, "job_launch", true);
    //if (shell->debug_mode)
        job_display(job);
    job_launch(shell, job, true);
    exec_rule_debug(shell, "job_launch", false);
    exec_rule_debug(shell, "pipeline", false);
    return (0);
}
