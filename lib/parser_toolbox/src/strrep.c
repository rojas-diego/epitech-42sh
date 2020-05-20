/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** strrep
*/

#include <stddef.h>

#include "parser_toolbox/strrep.h"

char *ptb_strrep(char *str, char a, char b)
{
    if (!str) {
        return (NULL);
    }
    for (size_t i = 0; str[i]; ++i) {
        if (str[i] == a) {
            str[i] = b;
        }
    }
    return (str);
}
