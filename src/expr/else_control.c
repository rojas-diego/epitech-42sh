
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_else_control
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for else_control expression.
*/
static struct expr_else_control_s *expr_else_control(struct grammar_s *this)
{
    struct expr_else_control_s *exp = malloc(
        sizeof(struct expr_else_control_s));
    unsigned int save_index = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_else_control_s));
    if (!grammar_match(this, 1, TOK_ELSE)) {
        free(exp);
        return NULL;
    }
    exp->else_token = grammar_get_previous(this);
    if (!grammar_match(this, 1, TOK_NEWLINE)) {
        this->error = true;
        free(exp);
        return NULL;
    }
    exp->newline = grammar_get_previous(this);
    exp->block = expr_block_w(this);
    if (!exp->block) {
        this->error = true;
        free(exp);
        return NULL;
    }
    return exp;
}

struct expr_else_control_s *expr_else_control_w(struct grammar_s *this)
{
    struct expr_else_control_s *exp;

    expr_print(this, "Else Control");
    exp = expr_else_control(this);
    expr_print_debug(this, exp);
    return exp;
}
