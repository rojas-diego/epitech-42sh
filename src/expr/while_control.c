
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
    (void)(this);
    return NULL;
}

struct expr_while_control_s *expr_while_control_w(struct grammar_s *this)
{
    struct expr_while_control_s *exp;

    expr_print(this, "While Control");
    exp = expr_while_control(this);
    expr_print_debug(this, exp);
    return exp;
}
