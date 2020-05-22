/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_program
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for program expression.
*/
void expr_program_destroy(struct expr_program_s *this)
{
    if (!this) {
        return;
    }
    expr_block_destroy(this->block);
    free(this);
}
