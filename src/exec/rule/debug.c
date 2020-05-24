/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule program
*/

#include <stdio.h>

#include "proto/exec/rule/debug.h"

static void job_display(struct job_s *job, int depth)
{
    for (struct process_s *s = job->first_process; s; s = s->next) {
        for (int i = 1; i < depth; i++) {
            dprintf(2, "│  ");
        }
        dprintf(2, "│ Process: ");
        for (size_t i = 0; i < s->argc; ++i) {
            dprintf(2, "%s ", s->argv[i]);
        }
        dprintf(2, "\n");
    }
}

void exec_rule_job_display(struct sh *shell, struct job_s *job)
{
    if (!shell->debug_mode) {
        return;
    }
    exec_rule_debug(shell, "Job", true);
    dprintf(2, "\033[38;2;230;70;100m");
    job_display(job, shell->debug.depth);
    exec_rule_debug(shell, "Job", false);
}

void exec_rule_debug(struct sh *shell, const char *rule, bool entering)
{
    if (!shell->debug_mode) {
        return;
    }
    shell->debug.depth += entering;
    dprintf(2, "\033[38;2;230;70;100m");
    for (int i = 1; i < shell->debug.depth; i++) {
        dprintf(2, "│  ");
    }
    if (entering) {
        dprintf(2, "┌─o \033[1m\033[38;2;150;150;220m%s\033[0m\n", rule);
    } else {
        shell->debug.depth -= 1;
        dprintf(2, "└─o \033[1m\033[38;2;150;150;220m%s\033[0m\n", rule);
    }
}
