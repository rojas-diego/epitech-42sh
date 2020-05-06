/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** test builtin_unsetenv
*/

/* getenv() */
#include <stdlib.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "builtin/unsetenv.h"

Test(builtin_unsetenv, simple_unsetenv)
{
    const char *var = "PWD";
    const char * const argv[] = {var, NULL};
    const char *getenved_value = NULL;

    builtin_unsetenv(argv);
    getenved_value = getenv(var);
    cr_assert_null(getenved_value);
}

Test(builtin_unsetenv, unsetenv_multiple_var)
{
    const char *var = "PWD";
    const char *var2 = "LANG";
    const char * const argv[] = {var, var2, NULL};
    const char *getenved_value = NULL;

    builtin_unsetenv(argv);
    getenved_value = getenv(var);
    cr_assert_null(getenved_value);
    getenved_value = getenv(var2);
    cr_assert_null(getenved_value);
}

Test(builtin_unsetenv, unsetenv_too_few_arguments)
{
    const char * const argv[] = {NULL};

    cr_redirect_stderr();
    builtin_unsetenv(argv);
    cr_assert_stderr_eq_str("unsetenv: Too few arguments.\n");
}
