/*
** EPITECH PROJECT, 2019
** parser_toolbox
** File description:
** ptb_characters
*/

#include <stdbool.h>

#include "parser_toolbox/includes.h"
#include "parser_toolbox/whitelist.h"

static const char PTB_WHITELIST_DIGIT[] = "0123456789";

/*
** @DESCRIPTION
**   Returns true string only composed of withelisted characters
**   Returns false otherwise.
*/
bool ptb_whitelist(const char *string, const char * restrict withelist)
{
    for (unsigned int i = 0; string[i]; ++i) {
        if (!ptb_includes(string[i], withelist)) {
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
    return (ptb_whitelist(string, PTB_WHITELIST_DIGIT));
}
