/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_pipeline
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for pipeline expression.
*/
void expr_pipeline_destroy(struct expr_pipeline_s *this)
{
    if (!this) {
        return;
    }
    expr_command_destroy(this->command);
    expr_pipeline_destroy(this->pipeline);
    free(this);
}
