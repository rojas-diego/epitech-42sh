/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_command
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for command expression.
*/
struct expr_command_s *expr_command(struct grammar_s *this)
{
    struct expr_command_s *exp = malloc(
        sizeof(struct expr_command_s));

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_command_s));
    exp->pipeline = expr_pipeline(this);
    if (exp->pipeline)
        exp->type = EXPR_PIPELINE;
    exp->shell_command = expr_shell_command(this);
    if (exp->shell_command && exp->type == EXPR_NULL)
        exp->type = EXPR_SHELL_COMMAND;
    exp->simple_command = expr_simple_command(this);
    if (exp->simple_command && exp->type == EXPR_NULL) {
        exp->type = EXPR_SIMPLE_COMMAND;
    } else {
        this->error = true;
        return NULL;
    }
    exp->command = expr_command(this);
    return exp;
}
