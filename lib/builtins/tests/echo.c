/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** test builtin_echo
*/

/* getenv() */
#include <stdlib.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "builtin/echo.h"

Test(builtin_echo, simple_echo)
{
    const char *arg = "echo";
    const char *arg2 = " more echo";
    const char * const argv[] = {arg, arg2, NULL};

    cr_redirect_stdout();
    builtin_echo(argv);
    cr_assert_stdout_eq_str("echo more echo\n");
}

Test(builtin_echo, echo_without_argument)
{
    const char * const argv[] = {NULL};

    cr_redirect_stdout();
    builtin_echo(argv);
    cr_assert_stdout_eq_str("\n");
}
