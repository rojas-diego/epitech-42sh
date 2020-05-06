/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** input_parse
*/

#include "types/shell.h"
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