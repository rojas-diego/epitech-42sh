
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_else_if_control
*/

#include <stdlib.h>
#include <string.h>

#include "proto/constants.h"
#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for else_if_control expression.
*/
static struct expr_else_if_control_s *expr_else_if_control(
    struct grammar_s *this
)
{
    struct expr_else_if_control_s *exp = malloc(
        sizeof(struct expr_else_if_control_s));
    unsigned int save_index = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_else_if_control_s));
    if (!grammar_match(this, 1, TOK_ELSE_IF)) {
        free(exp);
        return NULL;
    }
    exp->else_if_token = grammar_get_previous(this);
    exp->wordlist_expression = expr_wordlist_expression_w(this);
    if (!exp->wordlist_expression) {
        grammar_set_error(this, AST_INVALID_EXPRESSION);
        free(exp);
        return NULL;
    }
    if (!grammar_match(this, 1, TOK_THEN)) {
        grammar_set_error(this, AST_ELSE_IF_MISSING_THEN);
        free(exp);
        return NULL;
    }
    exp->then = grammar_get_previous(this);
    if (!grammar_match(this, 1, TOK_NEWLINE)) {
        grammar_set_error(this, AST_THEN_MISSING_NEWLINE);
        free(exp);
        return NULL;
    }
    exp->newline = grammar_get_previous(this);
    exp->block = expr_block_w(this);
    if (!exp->block) {
        grammar_set_error(this, AST_EMPTY_ELSE_IF);
        free(exp);
        return NULL;
    }
    save_index = this->index;
    exp->else_if_control = expr_else_if_control_w(this);
    if (!exp->else_if_control)
        this->index = save_index;
    return exp;
}

struct expr_else_if_control_s *expr_else_if_control_w(struct grammar_s *this)
{
    struct expr_else_if_control_s *exp;

    expr_print(this, "Else If Control");
    exp = expr_else_if_control(this);
    expr_print_debug(this, exp);
    return exp;
}
