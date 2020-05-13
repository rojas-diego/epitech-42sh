/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** ptb_characters
*/

#include <stdbool.h>

#include "parser_toolbox/consts.h"
#include "parser_toolbox/includes.h"
#include "parser_toolbox/whitelist.h"

/*
** @DESCRIPTION
**   Returns true string only composed of whitelisted characters
**   Returns false otherwise.
*/
bool ptb_whitelist(const char *string, const char * restrict whitelist)
{
    for (unsigned int i = 0; string[i]; ++i) {
        if (!ptb_includes(string[i], whitelist)) {
            return (false);
        }
    }
    return (true);
}

/*
** @DESCRIPTION
**   Returns true string only composed of digit characters
**   Returns false otherwise.
*/
bool ptb_whitelist_digit(const char *string)
{
    return (ptb_whitelist(string, PTB_DIGITS));
}

/*
** @DESCRIPTION
**   Returns true string only composed of alphanumeric characters
**   Returns false otherwise.
*/
bool ptb_whitelist_alphanum(const char *string)
{
    return (ptb_whitelist(string, PTB_ALPHANUM));
}
