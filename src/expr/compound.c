/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_compound
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for compound expression.
*/
static struct expr_compound_s *expr_compound(struct grammar_s *this)
{
    struct expr_compound_s *exp = malloc(sizeof(struct expr_compound_s));
    unsigned int save_index = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_compound_s));
    if (grammar_match(this, 1, TOK_AMPERSAND))
        exp->ampersand_start = grammar_get_previous(this);
    exp->grouping = expr_grouping_w(this);
    if (!exp->grouping)
        return (expr_free(exp));
    save_index = this->index;
    exp->jobs = expr_jobs_w(this);
    if (!exp->jobs)
        this->index = save_index;
    if (grammar_match(this, 1, TOK_AMPERSAND))
        exp->ampersand_start = grammar_get_previous(this);
    exp->separator = expr_separator_w(this);
    if (!exp->separator) {
        free(exp);
        return NULL;
    }
    return exp;
}

struct expr_compound_s *expr_compound_w(struct grammar_s *this)
{
    struct expr_compound_s *exp;

    expr_print(this, "Compound");
    exp = expr_compound(this);
    expr_print_debug(this, exp);
    return exp;
}
