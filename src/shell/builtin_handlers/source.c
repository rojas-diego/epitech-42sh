/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"

/* int fd_save = shell->fd; */
/* get fd() */
/* shell->fd = 0; */
/* shell_loop() */
int builtin_source_handler(
    struct sh *shell,
    const char * const *argv
)
{
    int tmp = shell->atty;

    if (argv[1] == NULL) {
        return (1);
    }
    shell->atty = 0;
    for (size_t i = 1; argv[i]; ++i) {
    }
    shell->atty = tmp;
    return (0);
}
