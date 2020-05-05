/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** builtin_setenv
*/

/* dprintf() */
#include <stdio.h>
/* setenv() */
#include <stdlib.h>

#include "builtin/display_env.h"
#include "parser_toolbox/argv_length.h"

/* */
#include "builtin/setenv.h"

void builtin_setenv(const char * const *argv)
{
    if (!argv[0]) {
        builtin_display_env();
        return;
    }
    if (ptb_argv_length(argv) > 2) {
        dprintf(2, "setenv: Too many arguments.\n");
        return;
    }
    if (setenv(argv[0], argv[1] ? argv[1] : "", 1) == -1) {
        dprintf(2, "ENOMEM\n");
        return;
    }
    return;
}
