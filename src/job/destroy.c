/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job
*/

#include <stdlib.h>

#include "proto/job/destroy.h"

void job_destroy(struct job_s *job)
{
    struct process_s *process = job->first_process;
    struct process_s *hold = NULL;

    while (process) {
        hold = process;
        process = process->next;
        for (size_t i = 0; i < hold->argc; ++i) {
            free(hold->argv[i]);
        }
        free(hold->argv);
        free(hold);
    }
    free(job);
}
