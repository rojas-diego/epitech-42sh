/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
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
