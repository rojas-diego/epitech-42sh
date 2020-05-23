/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** process
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "hasher/get_data.h"
#include "types/builtins.h"

#include "proto/sighandler.h"
#include "proto/job/process/launch.h"

static void process_launch_init_pipes(int fds[IO_COUNT])
{
    if (fds[IO_IN] != STDIN_FILENO) {
        dup2(fds[IO_IN], STDIN_FILENO);
        close(fds[IO_IN]);
    }
    if (fds[IO_OUT] != STDOUT_FILENO) {
        dup2(fds[IO_OUT], STDOUT_FILENO);
        close(fds[IO_OUT]);
    }
    if (fds[IO_ERR] != STDERR_FILENO) {
        dup2(fds[IO_ERR], STDERR_FILENO);
        close(fds[IO_ERR]);
    }
}

static void process_launch_exec(
    struct sh *shell,
    struct process_s *process
)
{
    builtin_handler *builtin = (builtin_handler *) hasher_get_data(
        shell->builtin, process->argv[0]
    );

    if (builtin && *builtin) {
        exit((*builtin)(shell, (const char * const *) process->argv));
    } else {
        execvp(process->argv[0], process->argv);
    }
}

void process_launch(
    struct sh *shell,
    struct job_s *job,
    struct process_s *process,
    int fds[IO_COUNT]
)
{
    pid_t pid;

    if (shell->atty) {
        pid = getpid();
        if (!job->pgid) {
            job->pgid = pid;
        }
        setpgid(pid, job->pgid);
        if (job->foreground) {
            tcsetpgrp(shell->fd, job->pgid);
        }
        term_set_signal_handling(SIG_DFL);
    }
    process_launch_init_pipes(fds);
    process_launch_exec(shell, process);
}
