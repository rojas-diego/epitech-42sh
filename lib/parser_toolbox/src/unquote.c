/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** ptb_remove_char
*/

#include <string.h>

#include "parser_toolbox/unquote.h"

void ptb_unquote(char *str)
{
    size_t len = strlen(str);

    if (len < 2) {
        return;
    }
    len -= 2;
    for (size_t i = 0; i < len; ++i) {
        str[i] = str[i + 1];
    }
    str[len] = '\0';
}
