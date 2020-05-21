/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_program
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for program expression.
*/
struct expr_program_s *expr_program(struct grammar_s *this)
{
    struct expr_program_s *exp = malloc(sizeof(struct expr_program_s));
    unsigned int save_index = this->index;

    printf("- Program.\n");
    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_program_s));
    exp->block = expr_block(this);
    if (!exp->block) {
        this->index = save_index;
    } if (grammar_match(this, 1, TOK_EOF)) {
        exp->eof = grammar_get_previous(this);
    } else {
        this->error = true;
    }
    return exp;
}
