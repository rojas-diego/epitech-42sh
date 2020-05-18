/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** input_parse_tokens - test
*/

#include <criterion/criterion.h>
#include <string.h>

#include "proto/input/parser.h"
#include "tests/mock_types.h"
#include "tests/tokens.h"

/*
** @DESCRIPTION
**   Tests basic functionality of the input_parse_tokens function.
*/
Test(input_parse_tokens, simple_testing)
{
    struct sh shell = MOCK_SH;
    struct token_s **table;

    shell.rawinput = strdup("ls | cat ls > file\n");
    input_parse_tokens(&shell);
    cr_assert_eq(node_size(shell.tokens), 7);
    table = (struct token_s **)node_to_table(shell.tokens);
    cr_assert_eq(table[0]->type, TOK_NAME);
    cr_assert_eq(table[1]->type, TOK_PIPE);
    cr_assert_eq(table[2]->type, TOK_NAME);
    cr_assert_eq(table[3]->type, TOK_NAME);
    cr_assert_eq(table[4]->type, TOK_GREAT);
    cr_assert_eq(table[5]->type, TOK_NAME);
    cr_assert_eq(table[6]->type, TOK_NEWLINE);
}

Test(input_parse_tokens, token_coverage)
{
    struct sh shell = MOCK_SH;
    struct token_s **table;

    shell.rawinput = strdup("> >>< << | & &&||if else\n");
    input_parse_tokens(&shell);
    cr_assert_eq(node_size(shell.tokens), 11);
    table = (struct token_s **)node_to_table(shell.tokens);
    cr_assert_eq(table[0]->type, TOK_GREAT);
    cr_assert_eq(table[1]->type, TOK_DGREAT);
    cr_assert_eq(table[2]->type, TOK_LESS);
    cr_assert_eq(table[3]->type, TOK_DLESS);
    cr_assert_eq(table[4]->type, TOK_PIPE);
    cr_assert_eq(table[5]->type, TOK_AMPERSAND);
    cr_assert_eq(table[6]->type, TOK_AND_IF);
    cr_assert_eq(table[7]->type, TOK_OR_IF);
    cr_assert_eq(table[8]->type, TOK_IF);
    cr_assert_eq(table[9]->type, TOK_ELSE);
    cr_assert_eq(table[10]->type, TOK_NEWLINE);
}

Test(input_parse_tokens, empty)
{
    struct sh shell = MOCK_SH;
    struct token_s **table;

    shell.rawinput = strdup("");
    input_parse_tokens(&shell);
    cr_assert_eq(node_size(shell.tokens), 0);
}
