/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** grammar_advance
*/

#include "proto/grammar.h"
#include "proto/expr.h"
#include "tests/tokens.h"

/*
** @DESCRIPTION
**   Consumes a pointer if there are tokens remaining in the array.
*/
struct token_s *grammar_advance(struct grammar_s *this)
{
    if (this->index < this->token_count) {
        if (this->debug) {
            expr_print_padding(this->depth);
            printf("└─ "
                "\033[1m\033[38;2;230;70;200m%s\033[0m\n",
                TOK_NAMES[this->tokens[this->index]->type]
            );
        }
        this->index++;
    }
    return this->tokens[this->index];
}
