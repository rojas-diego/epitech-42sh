
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_while_control
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for while_control expression.
*/
void expr_while_control_destroy(struct expr_while_control_s *this)
{
    if (!this) {
        return;
    }
    expr_conditional_destroy(this->conditional);
    expr_block_destroy(this->block);
    free(this);
}
