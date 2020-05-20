/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_wordfree
*/

#include <stdlib.h>
#include <wordexp.h>

void my_wordfree(wordexp_t *we)
{
    if (!we->we_wordv) {
        return;
    }
    for (size_t i = 0; i < we->we_wordc; ++i) {
        free(we->we_wordv[we->we_offs + i]);
    }
    free(we->we_wordv);
    we->we_wordv = 0;
    we->we_wordc = 0;
}
