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
#include "proto/input/parser.h"

/*
** @DESCRIPTION
**   This function is called if the validator's mask contains the vali_match
**   flag and is mostly meant to identify reserved words such as 'for' or
**   'then'.
**   If the vali_lower flag is provided then each scanned character will be
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
        if (va.mask & vali_lower)
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
**   It handles the vali_invalid, vali_alpha and vali_num mask flags.
**   Check the include.s for documentation on those flags.
*/
static bool token_validate_checks(const char c, const struct validator_s va)
{
    if (va.mask & vali_alpha
        && (ptb_range(c, 'a', 'z') || ptb_range(c, 'A', 'Z')))
            return true;
    if (va.mask & vali_num && ptb_range(c, '0', '9'))
        return true;
    if (va.valid && ptb_includes(c, va.valid))
        return !(va.mask & vali_invalid);
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

    if (va.mask & vali_match)
        return token_validate_exact_match(string, va);
    for (i = 0; string[i]; i++) {
        composite_value = token_validate_composite(string, &i, va);
        if (composite_value)
            continue;
        if (token_validate_checks(string[i], va) == false)
            break;
        if (va.maxlength && va.maxlength < i)
            return (0);
    }
    if (va.minlength && va.minlength > i)
        return (0);
    return (i);
}
