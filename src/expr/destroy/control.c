/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_control
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for control expression.
*/
void expr_control_destroy(struct expr_control_s *this)
{
    if (!this) {
        return;
    }
    expr_if_control_destroy(this->if_control);
    expr_while_control_destroy(this->while_control);
    expr_foreach_control_destroy(this->foreach_control);
    expr_repeat_control_destroy(this->repeat_control);
    free(this);
}
