/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** start
*/

#include <stdio.h>
#include <stdlib.h>

#include "proto/shell/shlvl_update.h"

/*
** @DESCRIPTION
**   Increase SHLVL env var by one if it exists,
**   Otherwise, it initialises it to 1
*/
int shlvl_update(void)
{
    const char *shlvl = getenv("SHLVL");
    char nb_stringified[16] = {'\0'};

    if (shlvl) {
        snprintf(nb_stringified, 16, "%d", atoi(shlvl) + 1);
    } else {
        nb_stringified[0] = '1';
    }
    return (setenv("SHLVL", nb_stringified, 1));
}
