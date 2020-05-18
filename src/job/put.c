/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#include "proto/job/put_in.h"
#include "proto/job/wait_for.h"

void job_put_in_background(struct job_s *job, bool does_continue)
{
   if (does_continue) {
       if (kill(-job->pgid, SIGCONT) < 0) {
           perror("kill (SIGCONT)");
       }
   }
}

void job_put_in_foreground(
    struct sh *shell,
    struct job_s *job,
    bool does_continue
)
{
    tcsetpgrp(shell->fd, job->pgid);
    if (does_continue) {
        tcsetattr(shell->fd, TCSADRAIN, &job->tmodes);
        if (kill(-job->pgid, SIGCONT) < 0) {
            perror("kill (SIGCONT)");
        }
    }
    job_wait_for(shell->job, job);
    tcsetpgrp(shell->fd, shell->pgid);
    tcgetattr(shell->fd, &job->tmodes);
    tcsetattr(shell->fd, TCSADRAIN, &shell->prompt.orig_term);
}
