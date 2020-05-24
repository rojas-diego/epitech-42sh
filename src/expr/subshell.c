/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_subshell
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for subshell expression.
*/
static struct expr_subshell_s *expr_subshell(struct grammar_s *this)
{
    struct expr_subshell_s *exp = malloc(
        sizeof(struct expr_subshell_s));
    unsigned int save_index __attribute__((unused)) = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_subshell_s));
    if (!grammar_match(this, 1, TOK_LPARANTH))
        return (expr_free(exp));
    exp->lparanth = grammar_get_previous(this);
    exp->grouping = expr_grouping_w(this);
    if (!exp->grouping)
        return (expr_free(exp));
    if (!grammar_match(this, 1, TOK_RPARANTH))
        return (expr_free(exp));
    exp->rparanth = grammar_get_previous(this);
    return exp;
}

struct expr_subshell_s *expr_subshell_w(struct grammar_s *this)
{
    struct expr_subshell_s *exp;

    expr_print(this, "Subshell");
    exp = expr_subshell(this);
    expr_print_debug(this, exp);
    return exp;
}
