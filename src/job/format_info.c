/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job
*/

#include <stdio.h>

#include "proto/job/format_info.h"

void job_format_info_launch_background(struct job_s *job)
{
    fprintf(stdout, "[%d]", job->launch_id);
    for (struct process_s *process =job->first_process;
    process; process = process->next) {
        fprintf(stdout, " %d", process->pid);
    }
    fprintf(stdout, "\n");
}

void job_format_info(struct job_s *job, const char *status)
{
    char state = '+';

    fprintf(
        stderr, "%*c %-30s%s\n",
        fprintf(stderr, "[%d]", job->launch_id) == 3 ? 2 : 1,
        state,
        status,
        job->command
    );
}
