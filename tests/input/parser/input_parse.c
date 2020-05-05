/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** input_parse - test
*/

#include <criterion/criterion.h>
#include <string.h>

#include "proto/input/parser.h"
#include "tests/mock_types.h"

/*
** @DESCRIPTION
**   Tests basic functionality of the input_parse function.
*/
Test(input_parse, simple_testing)
{
    struct sh shell = MOCK_SH;
    struct token_s **table;

    shell.rawinput = strdup("ls | cat `ls > file`\n");
    input_parse(&shell);
    cr_assert_eq(node_size(shell.tokens), 9);
    table = (struct token_s **)node_to_table(shell.tokens);
    cr_assert_eq(table[0]->type, TOK_ARGUMENT);
    cr_assert_eq(table[1]->type, TOK_PIPE);
    cr_assert_eq(table[2]->type, TOK_ARGUMENT);
    cr_assert_eq(table[3]->type, TOK_BACKTICKS);
    cr_assert_eq(table[4]->type, TOK_ARGUMENT);
    cr_assert_eq(table[5]->type, TOK_OUT_REDIR);
    cr_assert_eq(table[6]->type, TOK_ARGUMENT);
    cr_assert_eq(table[7]->type, TOK_BACKTICKS);
}