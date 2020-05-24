/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_foreach_control
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for foreach_control expression.
*/
void expr_foreach_control_destroy(struct expr_foreach_control_s *this)
{
    if (!this) {
        return;
    }
    expr_wordlist_expression_destroy(this->wordlist_expression);
    expr_block_destroy(this->block);
    free(this);
}
