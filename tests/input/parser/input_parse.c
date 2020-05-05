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

    shell.rawinput = strdup("ls | cat `ls > file`\n");
    input_parse(&shell);
    cr_assert_eq(node_size(shell.tokens), 9);
}