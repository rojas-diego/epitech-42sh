/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** token class
*/

#include <stdio.h>
#include <string.h>

/* Contains implicit includes for types */
#include "proto/token.h"
#include "constants/tokens.h"
#include "tests/tokens.h"

/*
** @DESCRIPTION
**   This function returns the malloc'ed string of a token.
*/
char *token_get_string(const struct token_s *this, const char *rawinput)
{
    return (strndup(rawinput + (*this).start, (*this).end - (*this).start));
}

/*
** @DESCRIPTION
**   Prints a token list with the token name and symbol.
*/
void token_list_print(struct node_s *head)
{
    struct token_s *this;

    for (struct node_s *curr = head; curr; curr = (*curr).next) {
        this = (*curr).data;
        printf("Token %s (%s)\n",
            TOK_NAMES[(*this).type], TOKENS[(*this).type]);
    }
}