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

void process_launch(
    struct sh *shell,
    struct process_s *process,
    int fds[IO_COUNT],
    int pgid,
    bool foreground
)
{
    pid_t pid;

    if (shell->atty) {
        pid = getpid();
        if (!pgid) {
            pgid = pid;
        }
        setpgid(pid, pgid);
        if (foreground) {
            tcsetpgrp(shell->fd, pgid);
        }
        term_set_signal_handling(SIG_DFL);
    }
    process_launch_init_pipes(fds);
    execvp(process->argv[0], process->argv);
    perror(process->argv[0]);
    exit(1);
}
