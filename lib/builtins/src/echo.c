/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** builtin_echo
*/

/* dprintf() */
#include <stdio.h>

/* */
#include "builtin/exit.h"

void builtin_echo(const char * const *argv)
{
    for (int i = 0; argv[i]; ++i) {
        dprintf(1, "%s", argv[i]);
    }
    dprintf(1, "\n");
    return;
}
