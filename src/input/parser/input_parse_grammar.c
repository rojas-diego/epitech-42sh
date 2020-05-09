/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** input_btree
*/

#include <stddef.h>

#include "types/grammar.h"
/* Contains implicit includes for types */
#include "proto/input/parser.h"

/*
** @DESCRIPTION
**   This function takes in a token list and populates a binary
**   tree to later be executed.
*/
void input_parse_grammar(struct sh *shell)
{
    struct grammar_s this = {0};

    this.tokens = (struct token_s **)node_to_table((*shell).tokens);
    if (this.tokens == NULL) {
        (*shell).error = ER_MALLOC;
        return;
    }
}
