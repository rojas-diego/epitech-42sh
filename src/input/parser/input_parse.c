/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** input_parse
*/

/* Contains implicit includes for types */
#include "proto/input/parser.h"

/*
** @DESCRIPTION
**   This is a wrapper function for the tokenisation and the grammar parsing.
*/
void input_parse(struct sh *shell)
{
    input_parse_tokens(shell);
    input_parse_grammar(shell);
}
