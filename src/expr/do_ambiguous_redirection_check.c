/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** do_ambiguous_redirection_check
*/

#include <stdlib.h>
#include <string.h>

#include "types/grammar.h"
#include "types/expr.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Ensures not more than one redirection is present in a command.
*/
int do_ambiguous_redirection_check(struct expr_command_s *this)
{
    struct expr_command_s *last = this;
    char *str = NULL;

    for (; last->command; last = last->command);
    //str = strndup(rawinput + this->start, last->end - this->start);
    //free(str);
    return (0);
}
