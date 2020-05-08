/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** token_validate
*/

#include <stdbool.h>

#include "parser_toolbox.h"

#include "types/input/token.h"
#include "types/input/validator.h"
#include "proto/input/parser.h"

/*
** @DESCRIPTION
**   This function is called if the validator's mask contains the VALI_MATCH
**   flag and is mostly meant to identify reserved words such as 'for' or
**   'then'.
**   If the VALI_LOWER flag is provided then each scanned character will be
**   locally put to lowercase if it uppercase.
** @RETURN
**   If the token did not match this function returns 0.
**   If the end of the 'valid' string was reached then its length is returned.
*/
static unsigned int token_validate_exact_match(
char const *string, const struct validator_s va)
{
    unsigned int i;
    int value;

    for (i = 0; string[i]; i++) {
        value = string[i];
        if (va.mask & VALI_LOWER)
            value = (ptb_range(string[i], 'A', 'Z')) ? value + 32 : value;
        if (va.valid[i] == '\0')
            break;
        if (string[i] != va.valid[i])
            return (0);
    }
    return (i);
}

/*
** @DESCRIPTION
**   This function ensures certain conditions from the validator's binary
**   mask are met.
**   It handles the VALI_INVALID, VALI_ALPHA and VALI_NUM mask flags.
**   Check the include.s for documentation on those flags.
*/
static bool token_validate_checks(const char c, const struct validator_s va)
{
    if (va.mask & VALI_ALPHA
        && (ptb_range(c, 'a', 'z') || ptb_range(c, 'A', 'Z')))
            return true;
    if (va.mask & VALI_NUM && ptb_range(c, '0', '9'))
        return true;
    if (va.valid && ptb_includes(c, va.valid))
        return !(va.mask & VALI_INVALID);
    return false;
}

/*
** @DESCRIPTION
**   This function will return the index of 'string' for which the conditions
**   of the validator_s struct were not met.
**   It allows identifying tokens based on the token with the longest match
**   value.
**   See the include.s for documentation on the validator_s structure
*/
unsigned int token_validate(char const *string, const struct validator_s va)
{
    bool composite_value;
    unsigned int i;

    if (va.mask & VALI_MATCH)
        return token_validate_exact_match(string, va);
    for (i = 0; string[i]; i++) {
        composite_value = token_validate_composite(string, &i, va);
        if (composite_value)
            continue;
        if (token_validate_checks(string[i], va) == false)
            break;
        if (va.maxlength && va.maxlength < i + 1)
            return (0);
    }
    if (va.minlength && va.minlength > i)
        return (0);
    return (i);
}
