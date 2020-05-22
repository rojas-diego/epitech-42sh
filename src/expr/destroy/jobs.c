/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_jobs
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for jobs expression.
*/
void expr_jobs_destroy(struct expr_jobs_s *this)
{
    if (!this) {
        return;
    }
    expr_grouping_destroy(this->grouping);
    expr_separator_destroy(this->separator);
    free(this);
}
