
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_repeat_control
*/

#include <stdlib.h>
#include <string.h>

#include "proto/constants.h"
#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for repeat_control expression.
*/
static struct expr_repeat_control_s *expr_repeat_control(
    struct grammar_s *this
)
{
    struct expr_repeat_control_s *exp = malloc(
        sizeof(struct expr_repeat_control_s));

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_repeat_control_s));
    if (!grammar_match(this, 1, TOK_REPEAT))
        return (expr_free(exp));
    exp->repeat = grammar_get_previous(this);
    if (!grammar_match(this, 1, TOK_WORD)) {
        grammar_set_error(this, AST_REPEAT_TOO_FEW_ARGS);
        return (expr_free(exp));
    }
    exp->word = grammar_get_previous(this);
    exp->grouping = expr_grouping_w(this);
    if (!exp->grouping) {
        grammar_set_error(this, AST_REPEAT_TOO_FEW_ARGS);
        return (expr_free(exp));
    }
    return exp;
}

struct expr_repeat_control_s *expr_repeat_control_w(struct grammar_s *this)
{
    struct expr_repeat_control_s *exp;

    expr_print(this, "Repeat Control");
    exp = expr_repeat_control(this);
    expr_print_debug(this, exp);
    return exp;
}
