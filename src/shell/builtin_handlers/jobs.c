/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include <stdio.h>
#include <string.h>

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"

#include "proto/job/continue.h"

int builtin_jobs_handler(struct sh *shell, const char * const *argv)
{
    if (builtins_utils_too_many_arguments(argv, 1)) {
        return (1);
    }
    if (argv[1] && strcmp(argv[1], "-l")) {
        dprintf(2, "Usage: jobs [ -l ].\n");
        return (1);
    }
    for (struct job_s *job = shell->job; job; job = job->next) {
    }
    return (0);
}
