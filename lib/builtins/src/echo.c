/*
** EPITECH PROJECT, 2020
** builtins
** File description:
** builtin_echo
*/

/* dprintf */
#include <stdio.h>
/* strcmp */
#include <string.h>
/* bool */
#include <stdbool.h>

/* */
#include "builtin/exit.h"

void builtin_echo(const char * const *argv)
{
    bool is_flag = (argv[0] && !strcmp(argv[0], "-n"));

    for (int i = is_flag; argv[i]; ++i) {
        dprintf(1, "%s%s", (i - is_flag) ? " " : "", argv[i]);
    }
    if (!is_flag) {
        dprintf(1, "\n");
    }
}
