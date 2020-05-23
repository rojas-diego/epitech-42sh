/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** grammar_toolbox
*/

#include <string.h>

#include "proto/grammar.h"

/*
** @DESCRIPTION
**   Fetches the previous token.
*/
struct token_s *grammar_get_previous(struct grammar_s *this)
{
    if (this->index > 0)
        return this->tokens[this->index - 1];
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

/*
** @DESCRIPTION
**   This function stores the parsing error from the building of the tree.
*/
void grammar_set_error(struct grammar_s *this, char const *message)
{
    if (!this->error_message)
        this->error_message = strdup(message);
    this->error = true;
}
