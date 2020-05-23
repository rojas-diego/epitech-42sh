/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** token class
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Contains implicit includes for types */
#include "proto/token.h"
#include "tests/tokens.h"
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

void token_print_debug(struct node_s *head, char const *rawinput)
{
    struct token_s *this;
    size_t printed = 0;
    char *dup;

    dprintf(2, "\n================== TOKENS ====================\n");
    for (struct node_s *curr = head; curr; curr = curr->next) {
        this = curr->data;
        dup = token_get_string(this, rawinput);
        printed += strlen(TOK_NAMES[this->type]) + strlen(dup) + 3;
        dprintf(2, "\033[1m\033[38;2;230;70;200m %s\033[0m(%s)",
            TOK_NAMES[this->type], dup);
        if (printed > 36) {
            printf("\n");
            printed = 0;
        }
        free(dup);
    }
    fflush(stderr);
}

struct token_s *token_new(enum tokent_e type)
{
    struct token_s *this = malloc(sizeof(struct token_s));

    if (!this)
        return NULL;
    memset(this, 0, sizeof(struct token_s));
    this->type = type;
    return this;
}
