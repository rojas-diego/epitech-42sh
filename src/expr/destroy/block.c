/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_block
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for block expression.
*/
void expr_block_destroy(struct expr_block_s *this)
{
    if (!this) {
        return;
    }
    expr_statement_destroy(this->statement);
    expr_block_destroy(this->block);
    free(this);
}


