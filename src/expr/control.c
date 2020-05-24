/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_control
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

int expr_control_sub_test(
    struct grammar_s *this,
    struct expr_control_s *exp,
    unsigned int save_index
)
{
    exp->if_control = expr_if_control_w(this);
    if (!exp->if_control)
        this->index = save_index;
    else
        return (1);
    exp->while_control = expr_while_control_w(this);
    if (!exp->while_control)
        this->index = save_index;
    else
        return (1);
    exp->foreach_control = expr_foreach_control_w(this);
    if (!exp->foreach_control)
        this->index = save_index;
    else
        return (1);
    return (0);
}

/*
** @DESCRIPTION
**   Rule for control expression.
*/
static struct expr_control_s *expr_control(struct grammar_s *this)
{
    struct expr_control_s *exp = malloc(sizeof(struct expr_control_s));
    unsigned int save_index = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_control_s));
    exp->if_inline_control = expr_if_inline_control_w(this);
    if (!exp->if_inline_control)
        this->index = save_index;
    else
        return (exp);
    if (expr_control_sub_test(this, exp, save_index))
        return (exp);
    exp->repeat_control = expr_repeat_control_w(this);
    if (!exp->repeat_control)
        return (expr_free(exp));
    return (exp);
}

struct expr_control_s *expr_control_w(struct grammar_s *this)
{
    struct expr_control_s *exp;

    expr_print(this, "Control");
    exp = expr_control(this);
    expr_print_debug(this, exp);
    return (exp);
}
