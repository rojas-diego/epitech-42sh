/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_subshell
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for subshell expression.
*/
void expr_subshell_destroy(struct expr_subshell_s *this)
{
    if (!this) {
        return;
    }
    expr_block_destroy(this->block);
    free(this);
}
