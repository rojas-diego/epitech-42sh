/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** input_btree
*/

/* Definition of NULL */
#include <stddef.h>

/* Prototypes for self */
/* This header contains implicit #includes for types. */
#include "proto/input/parser.h"

/*
** @DESCRIPTION
**   This function takes in a token list and populates a binary
**   tree to later be executed.
*/
void input_parse_grammar(struct sh *shell)
{
    struct bnode_s *tree __attribute__((unused)) = NULL;

    for (struct node_s *curr = (*shell).tokens; curr; curr = curr->next) {
        return;
    }
}
