/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_redirection
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for redirection expression.
*/
void expr_redirection_destroy(struct expr_redirection_s *this)
{
    if (!this) {
        return;
    }
    free(this);
}
