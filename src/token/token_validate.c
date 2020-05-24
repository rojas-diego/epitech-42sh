/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** token_validate
*/

#include <stdbool.h>

#include "parser_toolbox.h"
#include "myerror.h"

#include "proto/constants.h"
#include "proto/token.h"

/*
** @DESCRIPTION
**   This function skips the inhibitor from the string.
** @TODO
**   Raise an advor when the inhibitor is at the end of the line.
*/
void token_validate_inhibitors(char const *string, unsigned int *i, bool *adv)
{
    if (string[*i] != '\\') {
        *adv = false;
        return;
    }
    *adv = true;
    if (!string[*i + 1])
        return;
    else
        (*i)++;
}

/*
** @DESCRIPTION
**   This function skips the single quotes from the string.
** @TODO
**   Raise an error if there is an unmatched quote.
*/
void token_validate_squotes(char const *string, unsigned int *i, bool *adv)
{
    if (string[*i] != '\'') {
        *adv = false;
        return;
    }
    *adv = true;
    (*i)++;
    for (; string[*i]; (*i)++) {
        if (string[*i] == '\'')
            return;
    }
    my_error(ERR_WRITE, 84);
    (*i)--;
}

/*
** @DESCRIPTION
**   This function skips the single quotes from the string.
*/
void token_validate_bquotes(char const *string, unsigned int *i, bool *adv)
{
    if (string[*i] != '`') {
        *adv = false;
        return;
    }
    *adv = true;
    (*i)++;
    for (; string[*i]; (*i)++) {
        if (string[*i] == '`')
            return;
    }
    my_error(ERR_WRITE, 84);
    (*i)--;
}

/*
** @DESCRIPTION
**   This function skips the double quotes from the string.
*/
void token_validate_dquotes(char const *string, unsigned int *i, bool *adv)
{
    bool self_adv;

    if (string[*i] != '\"') {
        *adv = false;
        return;
    }
    *adv = true;
    (*i)++;
    for (; string[*i]; (*i)++) {
        token_validate_inhibitors(string, i, &self_adv);
        if (self_adv)
            continue;
        if (string[*i] == '\"')
            return;
    }
    my_error(ERR_WRITE, 84);
    (*i)--;
}

bool token_peek_characters(char const *string, char const *chars)
{
    for (unsigned int i = 0; string[i]; i++) {
        if (ptb_includes(string[i], WHITESPACE))
            continue;
        if (ptb_includes(string[i], chars))
            return (true);
    }
    return (false);
}
