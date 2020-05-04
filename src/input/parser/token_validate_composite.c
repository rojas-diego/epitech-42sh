/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** token_validate_composite
*/

#include <stdbool.h>

#include "types/input/token.h"
#include "types/input/validator.h"
#include "proto/input/parser.h"

/*
** @DESCRIPTION
**   This function applies the skipping of the contents of the quotes.s
*/
static void token_validate_composite_skip(
const char *string, unsigned int *i, const char token)
{
    char lastchar = 0;

    (*i)++;
    for (; string[*i]; (*i)++) {
        if (string[*i] == token && lastchar != '\\')
            return;
        lastchar = string[*i];
    }
}

/*
** @DESCRIPTION
**   This function ensures the valiCompososite mask flag's condition are met.
*/
bool token_validate_composite(
char const *string, unsigned int *i, const struct validator_s va)
{
    if (!(va.mask & valiComposite))
        return false;
    if (string[*i] == '\\') {
        if (string[*i + 1])
            (*i)++;
        else
            return true;
        return true;
    }
    if (string[*i] == '\'' || string[*i] == '\"') {
        token_validate_composite_skip(string, i, string[*i]);
        return true;
    }
    return false;
}
