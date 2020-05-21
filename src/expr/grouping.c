/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_grouping
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for grouping expression.
*/
struct expr_grouping_s *expr_grouping(struct grammar_s *this)
{
    struct expr_grouping_s *exp = malloc(
        sizeof(struct expr_grouping_s));
    unsigned int save_index __attribute__((unused)) = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_grouping_s));
    exp->pipeline = expr_pipeline(this);
    if (!exp->pipeline) {
        free(exp);
        return NULL;
    }
    if (!grammar_match(this, 2, TOK_AND_IF, TOK_OR_IF))
        return exp;
    exp->conditional = grammar_get_previous(this);
    exp->grouping = expr_grouping(this);
    if (!exp->grouping) {
        this->error = true;
        free(exp);
        return NULL;
    }
    return exp;
}
