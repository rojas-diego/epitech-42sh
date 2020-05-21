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
    unsigned int save_index = this->index;

    printf("- Block.\n");
    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_block_s));
    exp->statement = expr_statement(this);
    if (!exp->statement) {
        this->index = save_index;
        free(exp);
        return NULL;
    }
    save_index = this->index;
    exp->block = expr_block(this);
    if (!exp->block)
        this->index = save_index;
    return exp;
}
