/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** token_validate_token
*/

/* Contains implicit includes for types. */
#include "proto/input/token.h"

/*
** @DESCRIPTION
**   Validates a standard token.
*/
unsigned int token_validate_token(char const *string, char const *value)
{
    unsigned int i;

    for (i = 0; string[i]; i++) {
        if (string[i] != value[i])
            return 0;
        if (!value[i + 1])
            return (i + 1);
    }
    return (i);
}