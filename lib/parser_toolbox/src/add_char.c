/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** string
*/

/* strlen */
#include <string.h>

#include "parser_toolbox/add_char.h"

void ptb_add_char(char *str, size_t pos, char c)
{
    size_t size = strlen(str);

    for (; size > pos; --size) {
        str[size] = str[size - 1];
    }
    str[size] = c;
}
