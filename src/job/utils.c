/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job
*/

#include <stddef.h>

#include "proto/job/utils.h"

struct job_s *job_find_from_pdig(struct job_s *first_job, pid_t pgid)
{
    struct job_s *job;

    for (job = first_job; job; job = job->next) {
        if (job->pgid == pgid) {
            return (job);
        }
    }
    return (NULL);
}

int job_is_stopped(struct job_s *job)
{
    struct process_s *process;

    for (process = job->first_process; process; process = process->next) {
        if (!process->completed && !process->stopped) {
            return (0);
        }
    }
    return (1);
}

int job_is_completed(struct job_s *job)
{
    struct process_s *process;

    for (process = job->first_process; process; process = process->next) {
        if (!process->completed) {
            return (0);
        }
    }
    return (1);
}
