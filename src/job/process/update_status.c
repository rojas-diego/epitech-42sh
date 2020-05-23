/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job
*/

#include <stdio.h>
#include <sys/errno.h>
#include <sys/wait.h>

#include "proto/job/utils.h"
#include "proto/job/format_info.h"
#include "proto/job/process/update_status.h"

static const char *ERROR_STATUS[] = {
    "Hangup",
    "",
    "Quit",
    "Illegal instruction",
    "Trace/BPT trap",
    "Abort",
    "EMT trap",
    "Floating exception",
    "Killed",
    "Bus error",
    "Segmentation fault",
    "Bad system call",
    "",
    "Alarm clock",
    "Terminated",
    ""
};

static void job_process_handle_status(int status)
{
    dprintf(2, "%s", ERROR_STATUS[WTERMSIG(status) - 1]);
    if (WCOREDUMP(status)) {
        dprintf(2, " (core dumped)");
    }
    dprintf(2, "\n");
}

static int job_process_update_record_process(
    struct job_s *job,
    pid_t pid,
    int status
)
{
    struct process_s *process;

    for (process = job->first_process; process; process = process->next) {
        if (process->pid != pid)
            continue;
        process->status = status;
        if (WIFSTOPPED(status)) {
            fprintf(stderr, "\nSuspended\n");
            process->stopped = true;
            return (1);
        }
        process->completed = true;
        if (!WIFSIGNALED(status))
            return (1);
        if (job->foreground)
            job_process_handle_status(status);
        else
            job_format_info(job, "Terminated");
        return (1);
    }
    return (0);
}

int job_process_update_status(struct job_s *first_job, pid_t pid, int status)
{
    if (pid == 0 || (pid < 0 && errno == ECHILD)) {
        return (-1);
    }  else if (pid < 0) {
        perror("waitpid");
        return (-1);
    }
    for (struct job_s *job = first_job; job; job = job->next) {
        if (job_process_update_record_process(job, pid, status)) {
            return (0);
        }
    }
    return (-1);
}
