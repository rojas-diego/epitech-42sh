/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job launch
*/

#include <stdlib.h>

#include "types/job.h"

#include "proto/job/initialize.h"

static int process_initialize(struct job_s *job, char **argv)
{
    struct process_s *process = malloc(sizeof(struct process_s));

    if (process == NULL) {
        return (1);
    }
    *process = (struct process_s) {
        .next = NULL, .argv = argv,
        .pid = 0,
        .completed = false,
        .stopped = false,
        .status = 0
    };
    job->first_process = process;
    return (0);
}

int job_initialize(struct sh *shell, char **argv)
{
    struct job_s *job = malloc(sizeof(struct job_s));

    if (job == NULL) {
        return (1);
    }
    *job = (struct job_s) {
        .next = NULL, .command = NULL,
        .first_process = NULL,
        .pgid = 0,
        .notified = false,
        .tmodes = {0},
        .io = {0, 1, 2},
        .foreground = false,
        .launch_id = 1
    };
    if (process_initialize(job, argv)) {
        return (1);
    }
    shell->job = job;
    return (0);
}
