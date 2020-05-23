/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** token_validate_word
*/

#include "parser_toolbox.h"

/* Contains implicit includes for types. */
#include "proto/constants.h"
#include "proto/token.h"

/*
** @DESCRIPTION
**   Validator function for the IO_NUMBER token.
**   If the string consists solely of digits and the delimiter character is
**   one of '<' or '>', the token identifier IO_NUMBER shall be returned.
*/
unsigned int token_validate_io_number(
    char const *string,
    char const *value __attribute__((unused))
)
{
    unsigned int i = 0;

    if (string[i] == '1' || string[i] == '2') {
        if (token_peek_characters(string + i, "<>")) {
            return 1;
        }
    }
    return 0;
}

/*
** @DESCRIPTION
**   Validator function for WORD token.
**   In the shell command language, a token other than an operator. In some
**   cases a word is also a portion of a word token: in the various forms of
**   parameter expansion, such as ${name-word}, and variable assignment, such
**   as name=word, the word is the portion of the token depicted by word. The
**   concept of a word is no longer applicable following word expansions-only
**   fields remain.
*/
unsigned int token_validate_word(
    char const *string,
    char const *value __attribute__((unused))
)
{
    unsigned int i;
    bool adv;

    for (i = 0; string[i]; i++) {
        token_validate_dquotes(string, &i, &adv);
        token_validate_squotes(string, &i, &adv);
        token_validate_inhibitors(string, &i, &adv);
        if (adv)
            continue;
        if (ptb_range('A', 'Z', string[i]) && ptb_range('a', 'z', string[i]))
            continue;
        if (ptb_range('0', '9', string[i]))
            continue;
        if (!ptb_includes(string[i], TOK_WORD_BLACKLIST))
            continue;
        break;
    }
    return (i);
}
