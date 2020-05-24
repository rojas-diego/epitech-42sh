/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** do_ambiguous_redirection_check
*/

#include "types/grammar.h"
#include "types/expr.h"
#include "proto/expr.h"

/*
** @DESCRIPTION
**   Ensures not more than one redirection is present in a command.
*/
int do_ambiguous_redirection_check(struct expr_command_s *this)
{
    size_t wcount = 0;
    size_t rleft = 0;
    size_t rright = 0;

    while (this && wcount < 2) {
        if (this->word) {
            ++wcount;
        } else if ((this->redirection->redirection->type == TOK_GREAT
        || this->redirection->redirection->type == TOK_DGREAT)) {
            ++rright;
        } else
            ++rleft;
        if (rleft > 1 || rright > 1)
            return (1);
        this = this->command;
    }
    if (this && rright)
        return (1);
    return (0);
    for (; this && !this->redirection; this = this->command);
    if (!this)
        return (0);
    if ((this->command && this->command->command) || !(this->redirection->redirection->type
    == TOK_GREAT || this->redirection->redirection->type == TOK_DGREAT)) {
        return (1);
    } else if (!this->command)
        return (0);
    for (unsigned int i = this->redirection->word->end;;);
}
