/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_statement
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for statement expression.
*/
void expr_statement_destroy(struct expr_statement_s *this)
{
    if (!this) {
        return;
    }
    expr_compound_destroy(this->compound);
    expr_control_destroy(this->control);
    free(this);
}
