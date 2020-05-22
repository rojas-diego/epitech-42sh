/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** input_btree
*/

#include <stddef.h>

#include "types/grammar.h"
#include "proto/expr.h"
#include "proto/input/parser.h"

/*
** @DESCRIPTION
**   This function takes in a token list and populates a binary
**   tree to later be executed.
** @TODO
**   Find lib / libc implementation for 2d pointer array size getter.
*/
void input_parse_grammar(struct sh *shell)
{
    struct grammar_s this = {0};
    struct expr_program_s *expression;

    this.debug = shell->debug_mode;
    this.tokens = (struct token_s **)node_to_table(shell->tokens);
    if (this.tokens == NULL) {
        shell->error = ER_MALLOC;
        return;
    }
    for (; this.tokens[this.token_count]; this.token_count++);
    if (this.debug)
        printf("\n=============== AST DEBUG MODE ===============\n");
    expression = expr_program_w(&this);
    if (this.debug)
        printf("\nError: %s\n", (this.error) ? "Fatal" : "None");
    if (this.debug)
        printf("==============================================\n\n");
    shell->expression = this.error ? NULL : expression;
}
