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
#include "parser_toolbox/sub_str_chr.h"

/*
** @DESCRIPTION
**   Ensures not more than one redirection is present in a command.
*/
int do_ambiguous_redirection_check(
    struct grammar_s *gram,
    struct expr_command_s *this
)
{
    int rleft = 0;
    int rright = 0;

    for (bool pipe = false; this; this = this->command) {
        if (this->command && this->redirection && ptb_sub_str_chr(gram->
        rawinput, this->word ? this->word->end : this->redirection->word->end,
        this->command->word ? this->command->word->start :
        this->command->redirection->word->start, '|')) {
            if (rleft && pipe)
                return (1);
            rleft = 0;
            pipe = true;
            if (rright)
                return (1);
        }
        if (this->redirection) {
            rleft += (this->redirection->word->type == TOK_LESS
                || this->redirection->word->type == TOK_DLESS);
            rright += (this->redirection->word->type == TOK_GREAT
                || this->redirection->word->type == TOK_DGREAT);
        }
        if (rleft > 1 || rright > 1)
            return (1);
    }
    return (0);
}
