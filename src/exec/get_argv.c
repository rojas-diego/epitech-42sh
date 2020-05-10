/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt
*/

#include <stdio.h>
#include <wordexp.h>

#include "proto/exec/get_argv.h"

int exec_get_argv(wordexp_t *we, const char *input)
{
    if (wordexp(input, we, WRDE_UNDEF)) {
        /* handle */
        return (1);
    }
    dprintf(2, "\033[1m\033[38;2;150;150;220m");
    for (size_t i = 0; i < we->we_wordc; ++i)
        dprintf(2, "%s ", we->we_wordv[i]);
    dprintf(2, "\033[0m\n");
    return (0);
}
