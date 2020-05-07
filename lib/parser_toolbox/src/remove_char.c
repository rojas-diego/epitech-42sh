/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** ptb_remove_char
*/

#include "parser_toolbox/remove_char.h"

void ptb_remove_char(char *str, size_t pos)
{
    for (; str[pos + 1]; ++pos) {
        str[pos] = str[pos + 1];
    }
    str[pos] = '\0';
}
