/*
** EPITECH PROJECT, 2020
** builtins
** File description:
** test builtin_setenv
*/

/* getenv */
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

    cr_assert_eq(builtin_setenv(argv), SETENV_SUCCESS);
    getenved_value = getenv(var);
    cr_assert_str_eq(value, getenved_value);
}

Test(builtin_setenv, setenv_without_value)
{
    const char *var = "env_var";
    const char * const argv[] = {var, NULL};
    const char *getenved_value = NULL;

    cr_assert_eq(builtin_setenv(argv), SETENV_SUCCESS);
    getenved_value = getenv(var);
    cr_assert_str_eq("", getenved_value);
}

Test(builtin_setenv, setenv_too_many_arguments)
{
    const char *arg = "arg";
    const char * const argv[] = {arg, arg, arg, NULL};

    cr_redirect_stderr();
    cr_assert_eq(builtin_setenv(argv), SETENV_TOO_MANY_ARGS);
    cr_assert_stderr_eq_str("setenv: Too many arguments.\n");
}

Test(builtin_setenv, setenv_must_begin_with_a_letter)
{
    const char *arg = "1not_beginning_by_a_letter";
    const char * const argv[] = {arg, NULL};

    cr_redirect_stderr();
    cr_assert_eq(builtin_setenv(argv), SETENV_MUST_BEGIN_WITH_A_LETTER);
    cr_assert_stderr_eq_str(
        "setenv: Variable name must begin with a letter.\n"
    );
}

Test(builtin_setenv, setenv_must_contain_only_alphanum_chars)
{
    const char *arg = "containing_non_alph=num chars";
    const char * const argv[] = {arg, NULL};

    cr_redirect_stderr();
    cr_assert_eq(builtin_setenv(argv), SETENV_ALPHANUM_ONLY);
    cr_assert_stderr_eq_str(
        "setenv: Variable name must contain alphanumeric characters.\n"
    );
}
