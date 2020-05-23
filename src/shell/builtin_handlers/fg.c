/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include <stdio.h>

#include "proto/job/utils.h"

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"

#include "proto/job/continue.h"

int builtin_fg_handler(
    struct sh *shell,
    __attribute__((unused)) const char * const *argv
)
{
    for (struct job_s *job = shell->job; job; job = job->next) {
        if (job_is_stopped(job)) {
            job->foreground = false;
            job_continue(shell, job);
            return (0);
        }
    }
    fprintf(stderr, "fg: No current job.\n");
    return (1);
}
