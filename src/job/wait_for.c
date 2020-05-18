/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job
*/

#include "sys/wait.h"

#include "proto/job/utils.h"
#include "proto/job/wait_for.h"
#include "proto/job/process/update_status.h"

/* Check for processes that have status information available,
   blocking until all processes in the given job have reported.  */

void job_wait_for(struct job_s *first_job, struct job_s *job)
{
    int status;
    pid_t pid;

    do {
        pid = waitpid(WAIT_ANY, &status, WUNTRACED);
    } while (
        !job_process_update_status(first_job, pid, status)
        && !job_is_stopped(job)
        && !job_is_completed(job)
    );
}
