/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** grammar_toolbox
*/

#include "proto/grammar.h"

/*
** @DESCRIPTION
**   Fetches the previous token.
*/
struct token_s *grammar_get_previous(struct grammar_s *this)
{
    if (this->index > 0)
        return this->tokens[this->index];
    return 0;
}

/*
** @DESCRIPTION
**   Fetches the current token.
*/
struct token_s *grammar_peek(struct grammar_s *this)
{
    return this->tokens[this->index];
}
