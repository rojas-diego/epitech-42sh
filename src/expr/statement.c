/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_statement
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for statement expression.
*/
struct expr_statement_s *expr_statement(struct grammar_s *this)
{
    struct expr_statement_s *exp = malloc(sizeof(struct expr_statement_s));
    unsigned int save_index = this->index;

    printf("- Statement.\n");
    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_statement_s));
    exp->subshell = expr_subshell(this);
    if (!exp->subshell)
        this->index = save_index;
    else
        return exp;
    exp->compound_command = expr_compound_command(this);
    if (!exp->compound_command)
        this->index = save_index;
    else
        return exp;
    exp->control = expr_control(this);
    if (!exp->control) {
        this->index = save_index;
        free(exp);
        return NULL;
    }
    return exp;
}
