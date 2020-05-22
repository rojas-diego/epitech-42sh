/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule command
*/

#include <stdlib.h>

#include "proto/job/create.h"

struct job_s *job_create(int launch_id)
{
    struct job_s *job = malloc(sizeof(struct job_s));

    if (job == NULL) {
        return (NULL);
    }
    *job = (struct job_s) {
        .next = NULL,
        .command = NULL,
        .first_process = NULL,
        .pgid = 0,
        .notified = false,
        .tmodes = {0},
        .io = {IO_IN, IO_OUT, IO_ERR},
        .foreground = false,
        .launch_id = launch_id
    };
    return (job);
}
