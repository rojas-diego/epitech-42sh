/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** grammar_advance
*/

#include "proto/grammar.h"

/*
** @DESCRIPTION
**   Consumes a pointer if there are tokens remaining in the array.
*/
struct token_s *grammar_advance(struct grammar_s *this)
{
    if (this->index < this->token_count)
        this->index++;
    return this->tokens[this->index];
}
