
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_conditional
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for conditional expression.
*/
static struct expr_conditional_s *expr_conditional(
    struct grammar_s *this
)
{
    (void)(this);
    return NULL;
}

struct expr_conditional_s *expr_conditional_w(
    struct grammar_s *this
)
{
    struct expr_conditional_s *exp;

    expr_print(this, "Conditional");
    exp = expr_conditional(this);
    expr_print_debug(this, exp);
    return exp;
}
