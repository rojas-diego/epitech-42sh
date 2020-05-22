/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_separator
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for separator expression.
*/
void expr_separator_destroy(struct expr_separator_s *this)
{
    if (!this) {
        return;
    }
    free(this);
}
