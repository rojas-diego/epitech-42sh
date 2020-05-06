/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** token class
*/

#include <string.h>

/* Contains implicit includes for types */
#include "proto/input/parser.h"

/*
** @DESCRIPTION
**   This function returns the malloc'ed string of a token.
*/
char *token_get_string(const struct token_s *this, const char *rawinput)
{
    return (strndup(rawinput + (*this).start, (*this).end - (*this).start));
}
