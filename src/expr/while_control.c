
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_while_control
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for while_control expression.
*/
static struct expr_while_control_s *expr_while_control(struct grammar_s *this)
{
    struct expr_while_control_s *exp = malloc(
        sizeof(struct expr_while_control_s));
    unsigned int save_index __attribute__((unused)) = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_while_control_s));
    if (!grammar_match(this, 1, TOK_WHILE)) {
        free(exp);
        return NULL;
    }
    exp->while_token = grammar_get_previous(this);
    exp->conditional = expr_conditional_w(this);
    if (!exp->conditional) {
        free(exp);
        return NULL;
    }
    if (!grammar_match(this, 1, TOK_NEWLINE)) {
        free(exp);
        return NULL;
    }
    exp->conditional_newline = grammar_get_previous(this);
    exp->block = expr_block_w(this);
    if (!exp->block) {
        this->error = true;
        free(exp);
        return NULL;
    }
    if (!grammar_match(this, 1, TOK_END)) {
        free(exp);
        return NULL;
    }
    exp->end = grammar_get_previous(this);
    if (!grammar_match(this, 1, TOK_NEWLINE)) {
        free(exp);
        return NULL;
    }
    exp->end_newline = grammar_get_previous(this);
    return exp;
}

struct expr_while_control_s *expr_while_control_w(struct grammar_s *this)
{
    struct expr_while_control_s *exp;

    expr_print(this, "While Control");
    exp = expr_while_control(this);
    expr_print_debug(this, exp);
    return exp;
}
