/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** input_parse
*/

#include <stdio.h>

#include "myerror.h"

/* Contains implicit includes for types */
#include "proto/input/parser.h"

/*
** @DESCRIPTION
**   This is a wrapper function for the tokenisation and the grammar parsing.
*/
int input_parse(struct sh *shell)
{
    input_parse_tokens(shell);
    if (my_error(ERR_READ, 84)) {
        dprintf(2, "Error: Couldn't tokenise.\n");
        shell->error = 1;
        my_error(ERR_WRITE, 0);
        return (1);
    }
    return (input_parse_grammar(shell));
}
