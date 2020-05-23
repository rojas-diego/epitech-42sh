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
    size_t len = strlen(str) - 2;

    strncpy(str, str + 1, len);
    str[len] = '\0';
}
