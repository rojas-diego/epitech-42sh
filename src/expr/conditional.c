
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_conditional
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for conditional expression.
*/
static struct expr_conditional_s *expr_conditional(
    struct grammar_s *this
)
{
    struct expr_conditional_s *exp = malloc(sizeof(struct expr_conditional_s));

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_conditional_s));
    if (!grammar_match(this, 1, TOK_LPARANTH)) {
        free(exp);
        return NULL;
    }
    exp->lparanth = grammar_get_previous(this);
    if (!grammar_match(this, 1, TOK_WORD)) {
        free(exp);
        return NULL;
    }
    exp->word = grammar_get_previous(this);
    if (!grammar_match(this, 1, TOK_RPARANTH)) {
        free(exp);
        return NULL;
    }
    exp->rparanth = grammar_get_previous(this);
    return exp;
}

struct expr_conditional_s *expr_conditional_w(
    struct grammar_s *this
)
{
    struct expr_conditional_s *exp;

    expr_print(this, "Conditional");
    exp = expr_conditional(this);
    expr_print_debug(this, exp);
    return exp;
}
