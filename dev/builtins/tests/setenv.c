/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** test builtin_setenv
*/

/* getenv() */
#include <stdlib.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "builtin/setenv.h"

Test(builtin_setenv, simple_setenv)
{
    const char *var = "env_var";
    const char *value = "env_var_value";
    const char * const argv[] = {var, value, NULL};
    const char *getenved_value = NULL;

    builtin_setenv(argv);
    getenved_value = getenv(var);
    cr_assert_str_eq(value, getenved_value);
}

Test(builtin_setenv, setenv_without_value)
{
    const char *var = "env_var";
    const char * const argv[] = {var, NULL};
    const char *getenved_value = NULL;

    builtin_setenv(argv);
    getenved_value = getenv(var);
    cr_assert_str_eq("", getenved_value);
}

Test(builtin_setenv, setenv_too_many_arguments)
{
    const char *arg = "arg";
    const char * const argv[] = {arg, arg, arg, NULL};

    cr_redirect_stderr();
    builtin_setenv(argv);
    cr_assert_stderr_eq_str("setenv: Too many arguments.\n");
}
