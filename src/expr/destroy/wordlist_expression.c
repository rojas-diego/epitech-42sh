/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_wordlist_expression
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for wordlist_expression expression.
*/
void expr_wordlist_expression_destroy(struct expr_wordlist_expression_s *this)
{
    if (!this) {
        return;
    }
    expr_wordlist_destroy(this->wordlist);
    free(this);
}
