/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job
*/

#include <stdio.h>

#include "proto/job/format_info.h"

void job_format_info(struct job_s *job, const char *status)
{
    fprintf(stderr, "%ld (%s): %s\n", (long) job->pgid, status, job->command);
}
