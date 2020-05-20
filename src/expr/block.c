/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_block
*/

#include <stdlib.h>
#include <string.h>

#include "proto/grammar.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Rule for block expression.
*/
struct expr_block_s *expr_block(struct grammar_s *this)
{
    struct expr_block_s *exp = malloc(sizeof(struct expr_block_s));

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_block_s));
    exp->compound_command = expr_compound_command(this);
    if (!exp->compound_command) {
        free(exp);
        return NULL;
    }
    exp->block = expr_block(this);
    return exp;
}
