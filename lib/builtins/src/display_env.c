/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** builtin_setenv
*/

#include <stdio.h>

extern char **environ;

/* */
#include "builtin/display_env.h"

void builtin_display_env(void)
{
    for (int i = 0; environ[i]; ++i) {
        dprintf(1, "%s\n", environ[i]);
    }
}
