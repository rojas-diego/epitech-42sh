/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec builtins
*/

#include <unistd.h>

#include "types/shell.h"
#include "types/builtins.h"
#include "proto/exec/builtins.h"
#include "hasher/get_data.h"

int job_handle_if_builtin(
    struct sh *shell,
    __attribute__((unused)) struct job_s *job,
    struct process_s *process
)
{
    builtin_handler *func = (builtin_handler *) hasher_get_data(
        shell->builtin, process->argv[0]
    );
    int fd;

    if (func && *func) {
        fd = dup(1);
        dup2(job->io[IO_OUT], 1);
        shell->last_status = (*func)(
            shell, (const char * const *) process->argv
        );
        dup2(fd, 1);
        return (true);
    }
    return (false);
}
