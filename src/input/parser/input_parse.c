/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** input_parse
*/

#include <stdlib.h>
#include <stdio.h>

#include "mynode.h"
#include "myptb.h"

#include "types/shell.h"
#include "proto/input/parser.h"
#include "constants/validators.h"
#include "constants/tokens.h"

/*
** @DESCRIPTION
**   This function scans the next token in the input and advances the cursor.
*/
static struct token_s *input_scan(char const *string, unsigned int *index)
{
    struct token_s *this = calloc(1, sizeof(struct token_s));
    unsigned int record = 0;
    unsigned int current;
    unsigned int i;

    if (!this)
        return 0;
    (*this).start = *index;
    for (i = 0; i < TOKEN_COUNT; i++) {
        current = token_validate(string + *index, VALIDATORS[i]);
        if (current >= record) {
            record = current;
            (*this).type = i;
        }
    }
    (*this).end = *index + record;
    *index += (record) ? record - 1 : 1;
    return this;
}

/*
** @DESCRIPTION
**   This function translates the shell.rawinput variable into a token's list.
*/
void input_parse(struct sh *shell)
{
    node_t *tokens = NULL;
    token_t *new;

    for (unsigned int i = 0; (*shell).rawinput[i]; i++) {
        if (ptb_includes((*shell).rawinput[i], WHITESPACE))
            continue;
        new = input_scan((*shell).rawinput, &i);
        node_insert(&tokens, new);
        if (!(*shell).rawinput[i])
            i--;
    }
    node_reverse(&tokens);
    (*shell).tokens = tokens;
}
