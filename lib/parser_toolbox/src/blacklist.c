/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** ptb_characters
*/

#include <stdbool.h>

#include "parser_toolbox/includes.h"
#include "parser_toolbox/blacklist.h"

/*
** @DESCRIPTION
**   Returns true string doesn't contain any char of blacklisted characters
**   Returns false otherwise.
*/
bool ptb_blacklist(const char *string, const char * restrict blacklist)
{
    for (unsigned int i = 0; string[i]; ++i) {
        if (ptb_includes(string[i], blacklist)) {
            return (false);
        }
    }
    return (true);
}
