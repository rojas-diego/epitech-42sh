/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_repeat_control
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for repeat_control expression.
*/
void expr_repeat_control_destroy(struct expr_repeat_control_s *this)
{
    if (!this) {
        return;
    }
    expr_grouping_destroy(this->grouping);
    free(this);
}
