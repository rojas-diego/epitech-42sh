/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** token_validate
*/

#include <stdbool.h>

#include "myptb.h"

#include "types/input/token.h"
#include "types/input/validator.h"

/*
** @DESCRIPTION
**   This function ensures all the conditions from the binary mask are met.
*/
bool token_validate_checks(const char c, const struct validator_s va)
{
    if (va.mask & validatorAlpha
        && (ptb_range(c, 'a', 'z') || ptb_range(c, 'A', 'Z')))
            return true;
    if (va.mask & validatorNum && ptb_range(c, '0', '9'))
        return true;
    if (ptb_includes(c, va.valid))
        return true;
    return false;
}

/*
** @DESCRIPTION
**   This function returns the index of the provided string up until
**   the regex conditions were not met.
*/
unsigned int token_validate(char const *string, const struct validator_s va)
{
    unsigned int i;

    for (i = 0; string[i]; i++) {
        if (token_validate_checks(string[i], va) == false)
            break;
        if (va.maxlength && va.maxlength < i)
            return 0;
    }
    if (va.minlength && va.minlength > i)
        return 0;
    return i;
}
