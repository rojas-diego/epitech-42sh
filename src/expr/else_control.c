
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
struct expr_else_control_s *expr_else_control(struct grammar_s *this)
{
    (void)(this);
    return NULL;
}

struct expr_else_control_s *expr_else_control_w(struct grammar_s *this)
{
    struct expr_else_control_s *exp;

    expr_print(this, "Else Control");
    exp = expr_else_control(this);
    expr_print_debug(this, exp);
    return exp;
}
