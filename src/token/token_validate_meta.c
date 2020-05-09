/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** token_validate_word
*/

#include "parser_toolbox.h"

/* Contains implicit includes for types. */
#include "proto/constants.h"
#include "proto/input/token.h"

/*
** @DESCRIPTION
**   Validator function for ASSIGNMENT_WORD
**   If all the characters in the TOKEN preceding the first such <equals-sign>
**   form a valid name (see XBD Name), the token ASSIGNMENT_WORD shall be
**   returned.
** @NOTE
**   It's impossible for this token to be parsed during the tokenisation.
**   Instead, NAME tokens can be requalified as ASSIGNMENT_WORDs during the
**   parsing of the grammar.
*/
unsigned int token_validate_assignment_word(
    char const *string __attribute__((unused)),
    char const *value __attribute__((unused))
)
{
    return 0;
}

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
    unsigned int i;

    for (i = 0; string[i]; i++) {
        if (ptb_range('0', '9', string[i])) {
            continue;
        } else if (ptb_includes(string[i + 1], "<>")) {
            return (i + 1);
        } else {
            return 0;
        }
    }
    return 0;
}

/*
** @DESCRIPTION
**   Validator function for NAME token.
**   In the shell command language, a WORD consisting solely of underscores,
**   digits, and alphabetics from the portable character set. The first
**   character of a name is not a digit.
*/
unsigned int token_validate_name(
    char const *string,
    char const *value __attribute__((unused))
)
{
    unsigned int i;

    for (i = 0; string[i]; i++) {
        if (ptb_range('A', 'Z', string[i]) && ptb_range('a', 'z', string[i]))
            continue;
        if (ptb_range('0', '9', string[i]) && i)
            continue;
        if (!ptb_includes(string[i], TOK_WORD_BLACKLIST))
            continue;
        break;
    }
    return (i);
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