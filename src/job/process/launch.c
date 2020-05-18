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

void process_launch(
    struct sh *shell,
    struct process_s *process,
    int fds[IO_COUNT],
    bool foreground
)
{
    pid_t pid;

    if (shell->atty) {
      /* Put the process into the process group and give the process group
         the terminal, if appropriate.
         This has to be done both by the shell and in the individual
         child processes because of potential race conditions.  */
        pid = getpid();
        if (shell->pgid == 0) {
            shell->pgid = pid;
        }
        setpgid(pid, shell->pgid);
        if (foreground) {
            tcsetpgrp(shell->fd, shell->pgid);
        }

        /* Set the handling for job control signals back to the default.  */
        term_set_signal_handling(SIG_DFL);
    }

    /* Set the standard input/output channels of the new process.  */
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

    /* Exec the new process.  Make sure we exit.  */
    execvp(process->argv[0], process->argv);
    perror("execvp");
    exit(1);
}
