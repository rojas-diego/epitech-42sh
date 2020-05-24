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
static struct expr_wordlist_s *expr_wordlist(
    struct grammar_s *this
)
{
    struct expr_wordlist_s *exp = malloc(
        sizeof(struct expr_wordlist_s));
    unsigned int save_index __attribute__((unused)) = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_wordlist_s));
    if (!grammar_match(this, 1, TOK_WORD))
        return (expr_free(exp));
    exp->wordlist = expr_wordlist_w(this);
    return exp;
}

struct expr_wordlist_s *expr_wordlist_w(
    struct grammar_s *this
)
{
    struct expr_wordlist_s *exp;

    expr_print(this, "Wordlist");
    exp = expr_wordlist(this);
    expr_print_debug(this, exp);
    return exp;
}
