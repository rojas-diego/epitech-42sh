/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** test builtin_exit
*/

/* getenv() */
#include <stdlib.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "builtin/exit.h"

Test(builtin_exit, simple_exit, .exit_code = 42)
{
    const char *var = "42";
    const char * const argv[] = {var, NULL};

    builtin_exit(argv);
}

Test(builtin_exit, exit_without_argument, .exit_code = 0)
{
    const char * const argv[] = {NULL};

    builtin_exit(argv);
}

Test(builtin_exit, exit_too_many_arguments)
{
    const char *arg = "arg";
    const char * const argv[] = {arg, arg, NULL};

    cr_redirect_stderr();
    builtin_exit(argv);
    cr_assert_stderr_eq_str("exit: Expression Syntax.\n");
}

Test(builtin_exit, exit_with_bad_arg)
{
    const char *arg = "not_a_valid_exit_status";
    const char * const argv[] = {arg, NULL};

    cr_redirect_stderr();
    builtin_exit(argv);
    cr_assert_stderr_eq_str("exit: Expression Syntax.\n");
}
