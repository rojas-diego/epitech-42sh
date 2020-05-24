/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_if_inline_control
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for if_inline_control expression.
*/
static struct expr_if_inline_control_s *expr_if_inline_control(
    struct grammar_s *this
)
{
    struct expr_if_inline_control_s *exp = calloc(
        1, sizeof(struct expr_if_inline_control_s));

    if (!exp)
        exit(84);
    if (!grammar_match(this, 1, TOK_IF))
        return (expr_free(exp));
    exp->if_token = grammar_get_previous(this);
    exp->wordlist_expression = expr_wordlist_expression_w(this);
    if (!exp->wordlist_expression)
        return (expr_free(exp));
    exp->grouping = expr_grouping_w(this);
    if (!exp->grouping)
        return (expr_free(exp));
    if (!grammar_match(this, 1, TOK_NEWLINE)) {
        if (this->tokens[this->index]->type != TOK_EOF)
            return (expr_free(exp));
    } else
        exp->endif_newline = grammar_get_previous(this);
    return exp;
}

struct expr_if_inline_control_s *expr_if_inline_control_w(
    struct grammar_s *this
)
{
    struct expr_if_inline_control_s *exp;

    expr_print(this, "If Inline Control");
    exp = expr_if_inline_control(this);
    expr_print_debug(this, exp);
    return exp;
}
