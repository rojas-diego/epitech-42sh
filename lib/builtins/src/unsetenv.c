/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** builtin_setenv
*/

/* dprintf */
#include <stdio.h>
/* unsetenv */
#include <stdlib.h>

#include "parser_toolbox/argv_length.h"

/* */
#include "builtin/setenv.h"

void builtin_unsetenv(const char * const *argv)
{
    if (!argv[0]) {
        dprintf(2, "unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 0; argv[i]; ++i) {
        if (unsetenv(argv[i]) == -1) {
            dprintf(2, "ENOMEM\n");
            return;
        }
    }
    return;
}
