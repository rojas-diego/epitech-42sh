
/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_conditional
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for conditional expression.
*/
void expr_conditional_destroy(struct expr_conditional_s *this)
{
    if (!this) {
        return;
    }
    free(this);
}
