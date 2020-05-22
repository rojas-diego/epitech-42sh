/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_compound
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for compound expression.
*/
void expr_compound_destroy(struct expr_compound_s *this)
{
    if (!this) {
        return;
    }
    expr_grouping_destroy(this->grouping);
    expr_jobs_destroy(this->jobs);
    expr_separator_destroy(this->separator);
}
