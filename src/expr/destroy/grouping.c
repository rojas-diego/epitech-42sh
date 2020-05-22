/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_grouping
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for grouping expression.
*/
void expr_grouping_destroy(struct expr_grouping_s *this)
{
    if (!this) {
        return;
    }
    expr_pipeline_destroy(this->pipeline);
    expr_grouping_destroy(this->grouping);
    free(this);
}
