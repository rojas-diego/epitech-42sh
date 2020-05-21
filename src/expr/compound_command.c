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
    unsigned int save_index = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_compound_command_s));
    exp->grouping = expr_grouping_w(this);
    if (!exp->grouping)
        this->index = save_index;
    exp->separator = expr_separator_w(this);
    if (!exp->separator) {
        this->index = save_index;
        free(exp);
        return NULL;
    }
    return exp;
}

struct expr_compound_command_s *expr_compound_command_w(struct grammar_s *this)
{
    struct expr_compound_command_s *exp;

    expr_print(this, "Compound Command");
    exp = expr_compound_command(this);
    expr_print_debug(this, exp);
    return exp;
}
