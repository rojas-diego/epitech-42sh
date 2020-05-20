/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_pipeline
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for pipeline expression.
*/
struct expr_pipeline_s *expr_pipeline(struct grammar_s *this)
{
    struct expr_pipeline_s *exp = malloc(
        sizeof(struct expr_pipeline_s));

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_pipeline_s));
    exp->command1 =
    return exp;
}
