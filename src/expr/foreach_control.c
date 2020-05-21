
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_foreach_control
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for foreach_control expression.
*/
struct expr_foreach_control_s *expr_foreach_control(struct grammar_s *this)
{
    (void)(this);
    return NULL;
}

struct expr_foreach_control_s *expr_foreach_control_w(struct grammar_s *this)
{
    struct expr_foreach_control_s *exp;

    expr_print(this, "Foreach Control");
    exp = expr_foreach_control(this);
    expr_print_debug(this, exp);
    return exp;
}
