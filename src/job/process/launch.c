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
#include <errno.h>
#include <string.h>

#include "find_binary_in_path_env.h"

#include "hasher/get_data.h"
#include "types/builtins.h"

#include "proto/sighandler.h"
#include "proto/exec/magic/parse.h"
#include "proto/job/process/launch.h"
#include "proto/shell.h"

extern char **environ;

static const size_t NB_EXEC_ERROR = 18;

static const struct {
    int err_nbr;
    const char *status;
} EXEC_ERROR[] = {
    {E2BIG, "Argument list too long."},
    {EACCES, "Permission denied."},
    {EAGAIN, "EAGAIN."},
    {EFAULT, "Command not found."},
    {EINVAL, "EINVAL."},
    {EIO, "EIO."},
    {EISDIR, "EISDIR."},
    {ELIBBAD, "ELIBBAD."},
    {ELOOP, "ELOOP."},
    {EMFILE, "EMFILE."},
    {ENAMETOOLONG, "File name too long."},
    {ENFILE, "ENFILE."},
    {ENOENT, "Command not found."},
    {ENOEXEC, "Exec format error. Wrong Architecture."},
    {ENOMEM, "ENOMEM."},
    {ENOTDIR, "Not a directory."},
    {EPERM, "EPERM."},
    {ETXTBSY, "ETXTBSY."}
};

static void process_launch_find_exec_error(const char *binary_name)
{
    for (size_t i = 0; i < NB_EXEC_ERROR; ++i) {
        if (errno == EXEC_ERROR[i].err_nbr) {
            dprintf(2, "%s: %s\n", binary_name, EXEC_ERROR[i].status);
        }
    }
}

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
    char *fullpath = NULL;

    if (builtin && *builtin) {
        exit((*builtin)(shell, (const char * const *) process->argv));
    } else {
        if (strchr(process->argv[0], '/')) {
            execve(process->argv[0], process->argv, environ);
        } else {
            fullpath = find_binary_in_path_env(do_shell_getenv(shell, "PATH"), process->argv[0]);
            execve(fullpath ? fullpath : process->argv[0],
                process->argv, environ
            );
        }
        process_launch_find_exec_error(process->argv[0]);
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
    if (process->subshell) {
        do_subshell(shell, process->subshell);
    }
    process_launch_exec(shell, process);
}
