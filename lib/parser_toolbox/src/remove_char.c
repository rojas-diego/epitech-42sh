/*
** EPITECH PROJECT, 2020
** parser_toolbox
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
