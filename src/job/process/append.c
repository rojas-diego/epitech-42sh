/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule command
*/

#include "proto/job/process/append.h"

void job_process_append(struct job_s *job, struct process_s *new_process)
{
    struct process_s *process = job->first_process;

    if (!job->first_process) {
        job->first_process = new_process;
        return;
    }
    for (; process->next; process = process->next);
    process->next = new_process;
}
