/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job
*/

#include <stdlib.h>

#include "proto/job/free.h"

void job_free(struct job_s *job)
{
    struct process_s *process = job->first_process;
    struct process_s *hold = NULL;

    while (process) {
        hold = process;
        process = process->next;
        free(hold);
    }
    free(job);
}
