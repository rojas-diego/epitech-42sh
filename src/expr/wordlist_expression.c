
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_wordlist_expression
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for wordlist_expression expression.
*/
static struct expr_wordlist_expression_s *expr_wordlist_expression(
    struct grammar_s *this
)
{
    struct expr_wordlist_expression_s *exp = malloc(
        sizeof(struct expr_wordlist_expression_s));
    unsigned int save_index __attribute__((unused)) = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_wordlist_expression_s));
    if (!grammar_match(this, 1, TOK_LPARANTH)) {
        free(exp);
        return NULL;
    }
    exp->lparanth = grammar_get_previous(this);
    exp->wordlist = expr_wordlist_w(this);
    if (!exp->wordlist) {
        free(exp);
        return NULL;
    }
    if (!grammar_match(this, 1, TOK_RPARANTH)) {
        free(exp);
        return NULL;
    }
    exp->rparanth = grammar_get_previous(this);
    return exp;
}

struct expr_wordlist_expression_s *expr_wordlist_expression_w(
    struct grammar_s *this
)
{
    struct expr_wordlist_expression_s *exp;

    expr_print(this, "Wordlist Expression");
    exp = expr_wordlist_expression(this);
    expr_print_debug(this, exp);
    return exp;
}
