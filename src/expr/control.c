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

/*
** @DESCRIPTION
**   Rule for control expression.
*/
struct expr_control_s *expr_control(struct grammar_s *this)
{
    (void)(this);
    return NULL;
}

struct expr_control_s *expr_control_w(struct grammar_s *this)
{
    struct expr_control_s *exp;

    expr_print(this, "Control");
    exp = expr_control(this);
    expr_print_debug(this, "Control", exp);
    return exp;
}
