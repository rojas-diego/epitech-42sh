/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** ptb_characters
*/

#include <stdbool.h>

#include "parser_toolbox/includes.h"

/*
** @DESCRIPTION
**   Returns true if the c is contained in the values string.
**   Returns false otherwise.
*/
bool ptb_includes(const char c, const char *restrict values)
{
    for (unsigned int i = 0; values[i]; i++) {
        if (c == values[i]) {
            return (true);
        }
    }
    return (false);
}
