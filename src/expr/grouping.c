/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_grouping
*/

#include <stdlib.h>
#include <string.h>

#include "proto/constants.h"
#include "proto/grammar.h"
#include "proto/expr.h"

static int check_pipeline(
    struct grammar_s *this,
    struct expr_grouping_s *exp
)
{
    int ret = do_ambiguous_redirection_check(this, exp->pipeline);

    if (ret == 1) {
        grammar_set_error(this, AST_AMBIGUOUS_REDIRECTION1);
        return (1);
    } else if (ret == 2) {
        grammar_set_error(this, AST_AMBIGUOUS_REDIRECTION2);
        return (1);
    }
    return (0);
}

/*
** @DESCRIPTION
**   Rule for grouping expression.
*/
static struct expr_grouping_s *expr_grouping(struct grammar_s *this)
{
    struct expr_grouping_s *exp = malloc(
        sizeof(struct expr_grouping_s));
    unsigned int save_index __attribute__((unused)) = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_grouping_s));
    exp->pipeline = expr_pipeline_w(this);
    if (!exp->pipeline || check_pipeline(this, exp))
        return (expr_free(exp));
    if (!grammar_match(this, 2, TOK_AND_IF, TOK_OR_IF))
        return exp;
    exp->conditional = grammar_get_previous(this);
    exp->grouping = expr_grouping_w(this);
    if (!exp->grouping) {
        grammar_set_error(this, AST_NULL_COMMAND);
        return (expr_free(exp));
    }
    return exp;
}

struct expr_grouping_s *expr_grouping_w(struct grammar_s *this)
{
    struct expr_grouping_s *exp;

    expr_print(this, "Grouping");
    exp = expr_grouping(this);
    expr_print_debug(this, exp);
    return exp;
}
