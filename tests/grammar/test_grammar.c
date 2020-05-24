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

    shell.rawinput = strdup("if (1) then\nls\nelse if then (0)\nls\nendif\n");
    input_parse_tokens(&shell);
    input_parse_grammar(&shell);
}
