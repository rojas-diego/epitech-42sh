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
static struct expr_command_s *expr_command(struct grammar_s *this)
{
    struct expr_command_s *exp = malloc(
        sizeof(struct expr_command_s));
    unsigned int save_index = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_command_s));
    if (!grammar_match(this, 1, TOK_WORD)) {
        exp->redirection = expr_redirection_w(this);
        if (!exp->redirection) {
            free(exp);
            return NULL;
        }
    }
    exp->word = grammar_get_previous(this);
    save_index = this->index;
    exp->command = expr_command_w(this);
    if (!exp->command)
        this->index = save_index;
    return exp;
}

struct expr_command_s *expr_command_w(struct grammar_s *this)
{
    struct expr_command_s *exp;

    expr_print(this, "Command");
    exp = expr_command(this);
    expr_print_debug(this, exp);
    return exp;
}
