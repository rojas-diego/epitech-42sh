/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_else_if_control
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for else_if_control expression.
*/
void expr_else_if_control_destroy(struct expr_else_if_control_s *this)
{
    if (!this) {
        return;
    }
    expr_wordlist_expression_destroy(this->wordlist_expression);
    expr_block_destroy(this->block);
    expr_else_if_control_destroy(this->else_if_control);
    free(this);
}
