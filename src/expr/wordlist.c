
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_wordlist
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for wordlist expression.
*/
struct expr_wordlist_s *expr_wordlist(
    struct grammar_s *this
)
{
    (void)(this);
    return NULL;
}

struct expr_wordlist_s *expr_wordlist_w(
    struct grammar_s *this
)
{
    struct expr_wordlist_s *exp;

    expr_print(this, "Wordlist Expression");
    exp = expr_wordlist(this);
    expr_print_debug(this, exp);
    return exp;
}
