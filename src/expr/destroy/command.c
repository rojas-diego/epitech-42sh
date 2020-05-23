/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** expr_command
*/

/* free */
#include <stdlib.h>

#include "proto/expr_destroy.h"

/*
** @DESCRIPTION
**   Rule for command expression.
*/
void expr_command_destroy(struct expr_command_s *this)
{
    if (!this) {
        return;
    }
    expr_redirection_destroy(this->redirection);
    expr_command_destroy(this->command);
    free(this);
}
