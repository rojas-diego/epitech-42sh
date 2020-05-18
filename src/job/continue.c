/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** process
*/

#include "proto/job/put_in.h"
#include "proto/job/continue.h"

static void mark_job_as_running(struct job_s *job)
{
    struct process_s *process;

    for (process = job->first_process; process; process = process->next) {
        process->stopped = false;
    }
    job->notified = false;
}

void job_continue(struct sh *shell, struct job_s *job, bool foreground)
{
    mark_job_as_running(job);
    if (foreground) {
        job_put_in_foreground(shell, job, true);
    } else {
        job_put_in_background(job, true);
    }
}
