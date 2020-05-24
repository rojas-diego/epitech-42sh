/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** test_grammar
*/

#include <criterion/criterion.h>
#include <string.h>

#include "proto/token.h"
#include "proto/grammar.h"
#include "proto/input/parser.h"
#include "types/expr.h"
#include "tests/mock_types.h"

Test(input_parse_grammar, simple_command)
{
    struct sh shell = MOCK_SH;

    shell.rawinput = strdup("ls");
    input_parse_tokens(&shell);
    input_parse_grammar(&shell);
}

Test(input_parse_grammar, advanced_command)
{
    struct sh shell = MOCK_SH;

    shell.rawinput = strdup("ls | cat -e || ls \"this\" && ls > file");
    input_parse_tokens(&shell);
    input_parse_grammar(&shell);
}

Test(input_parse_grammar, control_flow)
{
    struct sh shell = MOCK_SH;
    struct expr_if_control_s *expression = NULL;

    shell.rawinput = strdup("if (1 && 1) then\nls\nelse if (0) then\nls\nendif\n");
    input_parse_tokens(&shell);
    input_parse_grammar(&shell);
    expression = shell.expression->block->statement->control->if_control;
    cr_assert_not_null(shell.expression);
    cr_assert_not_null(expression);
}
