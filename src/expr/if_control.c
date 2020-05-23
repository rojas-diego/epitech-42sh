/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_if_control
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for if_control expression.
*/
static struct expr_if_control_s *expr_if_control(struct grammar_s *this)
{
    struct expr_if_control_s *exp = malloc(sizeof(struct expr_if_control_s));
    unsigned int save_index = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_if_control_s));
    if (!grammar_match(this, 1, TOK_IF)) {
        free(exp);
        return NULL;
    }
    exp->if_token = grammar_get_previous(this);
    exp->wordlist_expression = expr_wordlist_expression_w(this);
    if (!exp->wordlist_expression) {
        free(exp);
        return NULL;
    }
    if (!grammar_match(this, 1, TOK_THEN)) {
        free(exp);
        return NULL;
    }
    exp->then = grammar_get_previous(this);
    if (!grammar_match(this, 1, TOK_NEWLINE)) {
        free(exp);
        return NULL;
    }
    exp->then_newline = grammar_get_previous(this);
    save_index = this->index;
    exp->block = expr_block_w(this);
    if (!exp->block)
        this->index = save_index;
    save_index = this->index;
    exp->else_if_control = expr_else_if_control_w(this);
    if (!exp->else_if_control)
        this->index = save_index;
    if (!grammar_match(this, 1, TOK_ENDIF)) {
        free(exp);
        return NULL;
    }
    exp->endif = grammar_get_previous(this);
    if (!grammar_match(this, 1, TOK_NEWLINE)) {
        free(exp);
        return NULL;
    }
    exp->endif_newline = grammar_get_previous(this);
    return exp;
}

struct expr_if_control_s *expr_if_control_w(struct grammar_s *this)
{
    struct expr_if_control_s *exp;

    expr_print(this, "If Control");
    exp = expr_if_control(this);
    expr_print_debug(this, exp);
    return exp;
}
