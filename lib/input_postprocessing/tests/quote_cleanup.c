/*
** EPITECH PROJECT, 2020
** input_postprocessing
** File description:
** test builtin_setenv
*/

#include <string.h>

#include <criterion/criterion.h>

#include "postprocess/quote_cleanup.h"

Test(ipp_quote_cleanup, very_simple_quote_cleanup)
{
    char *dirty_string = strdup("\"I am not so dirty\"");

    ipp_quote_cleanup(dirty_string);
    cr_assert_str_eq(dirty_string, "I am not so dirty");
}

Test(ipp_quote_cleanup, simple_quote_cleanup)
{
    char *dirty_string = strdup("\"I \"a'm a bit '\"dirty \\\"\"':)\\'");

    ipp_quote_cleanup(dirty_string);
    cr_assert_str_eq(dirty_string, "I am a bit dirty \":)\\");
}

Test(ipp_quote_cleanup, medium_quote_cleanup)
{
    char *dirty_string = strdup("I' am 'gen'ui'\"nel\"'y 'dirty");

    ipp_quote_cleanup(dirty_string);
    cr_assert_str_eq(dirty_string, "I am genuinely dirty");
}

Test(ipp_quote_cleanup, hard_quote_cleanup)
{
    char *dirty_string = strdup("\"\"\"\"I\" 'a'm \"'s'o\" \\\"dirty\"");

    ipp_quote_cleanup(dirty_string);
    cr_assert_str_eq(dirty_string, "I 'a'm so \"dirty");
}

Test(ipp_quote_cleanup, tricky_single_quote)
{
    char *dirty_string = strdup("'""\\'\\'");

    ipp_quote_cleanup(dirty_string);
    cr_assert_str_eq(dirty_string, "\\'");
}
