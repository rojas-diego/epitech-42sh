/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_compound_command
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for compound_command expression.
*/
struct expr_compound_command_s *expr_compound_command(struct grammar_s *this)
{
    struct expr_compound_command_s *exp = malloc(
        sizeof(struct expr_compound_command_s));

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_compound_command_s));
    exp->command = expr_command(this);
    if (!exp->command) {
        free(exp);
        return NULL;
    }
    exp->compound_command = expr_compound_command(this);
    return exp;
}
