/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** input_btree
*/

#include <stdlib.h>

#include "types/grammar.h"
#include "proto/expr.h"
#include "proto/input/parser.h"

static void input_parse_grammar_debug(struct sh *shell, struct grammar_s *this)
{
    struct expr_program_s *expression;

    if (this->debug)
        dprintf(2, "\n=============== AST DEBUG MODE ===============\n");
    expression = expr_program_w(this);
    if (this->error) {
        if (this->error_message) {
            dprintf(2, "\n\033[1m\033[38;2;230;70;100mError: %s.\033[0m\n",
                    this->error_message);
        } else {
            dprintf(2, "\n\033[1m\033[38;2;230;70;100mUnreso\
lved Error.\033[0m\n");
        }
    } else if (!this->error && this->debug) {
        printf("\n\033[1m\033[38;2;150;200;0mTree Clean.\033[0m\n");
    }
    if (this->debug)
        dprintf(2, "==============================================\n\n");
    shell->expression = this->error ? NULL : expression;
}

/*
** @DESCRIPTION
**   This function takes in a token list and populates a binary
**   tree to later be executed.
** @TODO
**   Find lib / libc implementation for 2d pointer array size getter.
*/
int input_parse_grammar(struct sh *shell)
{
    struct grammar_s this = {0};

    this.debug = shell->debug_mode;
    this.tokens = (struct token_s **)node_to_table(shell->tokens);
    if (this.tokens == NULL) {
        shell->error = ER_MALLOC;
        return (1);
    }
    for (; this.tokens[this.token_count]; this.token_count++);
    input_parse_grammar_debug(shell, &this);
    return (this.error);
}
