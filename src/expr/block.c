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
static struct expr_block_s *expr_block(struct grammar_s *this)
{
    struct expr_block_s *exp = malloc(sizeof(struct expr_block_s));
    unsigned int save_index = this->index;

    if (!exp)
        exit(84);
    memset(exp, 0, sizeof(struct expr_block_s));
    save_index = this->index;
    exp->statement = expr_statement_w(this);
    if (!exp->statement) {
        this->index = save_index;
        return (expr_free(exp));
    }
    while (grammar_match(this, 2, TOK_NEWLINE, TOK_SEMI));
    save_index = this->index;
    exp->block = expr_block_w(this);
    if (!exp->block)
        this->index = save_index;
    return (exp);
}

struct expr_block_s *expr_block_w(struct grammar_s *this)
{
    struct expr_block_s *exp;

    expr_print(this, "Block");
    exp = expr_block(this);
    expr_print_debug(this, exp);
    return (exp);
}
