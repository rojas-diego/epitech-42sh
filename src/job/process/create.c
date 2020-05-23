/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule command
*/

#include <stdlib.h>

#include "proto/job/process/create.h"

static const size_t PROCESS_ARGV_DEFAULT_SIZE = 32;

struct process_s *process_create(void)
{
    struct process_s *process = malloc(sizeof(struct process_s));

    if (process == NULL) {
        return (NULL);
    }
    *process = (struct process_s) {
        .next = NULL,
        .argv = calloc(PROCESS_ARGV_DEFAULT_SIZE, sizeof(char *)),
        .argc = 0,
        .max_argc = PROCESS_ARGV_DEFAULT_SIZE,
        .pid = 0,
        .completed = false,
        .stopped = false,
        .status = 0
    };
    return (process);
}
