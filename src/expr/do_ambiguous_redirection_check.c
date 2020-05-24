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


static void do_count_redirection_pipeline(
    struct expr_command_s *this,
    int red[2]
)
{
    if (!this)
        return;
    for (; this; this = this->command) {
        if (!this->redirection)
            continue;
        red[0] += (this->redirection->redirection->type == TOK_LESS
            || this->redirection->redirection->type == TOK_DLESS);
        red[1] += (this->redirection->redirection->type == TOK_GREAT
            || this->redirection->redirection->type == TOK_DGREAT);
    }
}

/*
** @DESCRIPTION
**   Ensures not more than one redirection is present in a command.
*/
int do_ambiguous_redirection_check(
    __attribute__((unused)) struct grammar_s *gram,
    struct expr_pipeline_s *this
)
{
    int red[2] = {0, 0};

    do_count_redirection_pipeline(this->command, red);
    if (red[0] > 1 || red[1] > 1 || (red[1] > 0 && this->pipeline))
        return ((red[1] > 1 || (red[1] > 0 && this->pipeline)) ? 2 : 1);
    red[0] = 1;
    red[1] = 0;
    for (this = this->pipeline; this; this = this->pipeline) {
        do_count_redirection_pipeline(this->command, red);
        if (red[0] > 1 || (red[1] > 0 && this->pipeline))
            return ((red[1] > 0) ? 2 : 1);
    }
    return (0);
}
