/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include <stdio.h>
#include <stdlib.h>

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"

int builtin_termname_handler(
    __attribute__((unused)) struct sh *shell,
    const char * const *argv
)
{
    const char *term = NULL;

    if (!argv[1]) {
        term = getenv("TERM");
        if (term) {
            dprintf(1, "%s\n", term);
        }
    } else if (!argv[2]) {
    } else {
        dprintf(2, "%s: Too many arguments.\n", argv[0]);
        return (1);
    }
    return (0);
}
