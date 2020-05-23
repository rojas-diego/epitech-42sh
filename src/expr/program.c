/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_program
*/

#include <stdlib.h>
#include <string.h>

#include "proto/constants.h"
#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for program expression.
*/
static struct expr_program_s *expr_program(struct grammar_s *this)
{
    struct expr_program_s *exp = malloc(sizeof(struct expr_program_s));
    unsigned int save_index = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_program_s));
    exp->block = expr_block_w(this);
    if (!exp->block) {
        this->index = save_index;
    } if (grammar_match(this, 1, TOK_EOF)) {
        exp->eof = grammar_get_previous(this);
    } else if (this->index != this->token_count) {
        grammar_set_error(this, AST_UNEXPECTED_TOKENS);
        free(exp);
        return NULL;
    }
    return exp;
}

struct expr_program_s *expr_program_w(struct grammar_s *this)
{
    struct expr_program_s *exp;

    expr_print(this, "Program");
    exp = expr_program(this);
    expr_print_debug(this, exp);
    return exp;
}
