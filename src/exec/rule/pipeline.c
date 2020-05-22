/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule pipeline
*/

#include "proto/exec/rule/debug.h"
void exec_rule_job_display(struct sh *shell, struct job_s *job);

#include "proto/job/create.h"
#include "proto/job/launch.h"
#include "proto/exec/rule/command.h"
#include "proto/exec/rule/pipeline.h"

#include <stdio.h>

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
    exec_rule_job_display(shell, job);
    job_launch(shell, job, true);
    exec_rule_debug(shell, "job_launch", false);
    exec_rule_debug(shell, "pipeline", false);
    return (0);
}
