
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_repeat_control
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for repeat_control expression.
*/
static struct expr_repeat_control_s *expr_repeat_control(
    struct grammar_s *this
)
{
    (void)(this);
    return NULL;
}

struct expr_repeat_control_s *expr_repeat_control_w(struct grammar_s *this)
{
    struct expr_repeat_control_s *exp;

    expr_print(this, "repeat Control");
    exp = expr_repeat_control(this);
    expr_print_debug(this, exp);
    return exp;
}
