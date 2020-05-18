/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** grammar_match
*/

#include <stdarg.h>

#include "types/grammar.h"
#include "proto/grammar.h"

/*
** @DESCRIPTION
**   Returns true if the token is one of the variadic argument provided.
*/
bool grammar_match(struct grammar_s *this, unsigned long int count, ...)
{
    va_list ap;

    va_start(ap, count);
    for (; count; --count) {
        if (this->index > this->token_count) {
            return (false);
        } if (va_arg(ap, unsigned long int) ==
            this->tokens[this->index]->type) {
            grammar_advance(this);
            return (true);
        }
    }
    return (false);
}
