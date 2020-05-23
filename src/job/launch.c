/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job launch
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "proto/job/launch.h"
#include "proto/job/put_in.h"
#include "proto/job/process/launch.h"
#include "proto/job/format_info.h"
#include "proto/job/wait_for.h"

static void job_launch_process_clear_pipe(
    int pipe_fd[2],
    int fildes[IO_COUNT]
)
{
    if (fildes[IO_IN] != IO_IN)
        close(fildes[IO_IN]);
    if (fildes[IO_OUT] != IO_OUT)
        close(fildes[IO_OUT]);
    if (fildes[IO_ERR] != IO_ERR)
        close(fildes[IO_OUT]);
    if (pipe_fd != IO_IN)
        fildes[IO_IN] = pipe_fd[0];
}

static pid_t job_launch_process_fork(
    struct sh *shell,
    struct job_s *job,
    struct process_s *process,
    int fildes[IO_COUNT]
)
{
    pid_t pid = fork();

    if (pid == 0) {
        process_launch(shell, job, process, fildes);
        exit(1);
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    }
    return (pid);
}

static void job_launch_handle_parent(
    struct job_s *job,
    struct process_s *process,
    int atty,
    pid_t pid
)
{
    process->pid = pid;
    if (atty) {
        if (!job->pgid) {
            job->pgid = pid;
        }
        setpgid(pid, job->pgid);
    }
}

static void job_launch_handle_launched_processes(
    struct sh *shell,
    struct job_s *job,
    bool foreground
)
{
    if (!shell->atty) {
        job_wait_for(shell->job, job);
    } else if (foreground) {
        job_put_in_foreground(shell, job, false);
    } else {
        job_put_in_background(job, false);
    }
}

void job_launch(struct sh *shell, struct job_s *job, bool foreground)
{
    struct process_s *process = NULL;
    int pipe_fd[2] = {IO_IN, IO_IN};
    int fildes[IO_COUNT] = {job->io[IO_IN], IO_OUT, IO_ERR};

    for (process = job->first_process; process; process = process->next) {
        if (process->next) {
            if (pipe(pipe_fd) < 0)
                exit(1);
            fildes[IO_OUT] = pipe_fd[1];
            fildes[IO_ERR] = IO_ERR;
        } else {
            fildes[IO_OUT] = job->io[IO_OUT];
            fildes[IO_ERR] = job->io[IO_ERR];
        }
        job_launch_handle_parent(job, process, shell->atty,
            job_launch_process_fork(shell, job, process, fildes));
        job_launch_process_clear_pipe(pipe_fd, fildes);
    }
    job_launch_handle_launched_processes(shell, job, foreground);
}
