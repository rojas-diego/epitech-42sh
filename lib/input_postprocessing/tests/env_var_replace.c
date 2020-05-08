/*
** EPITECH PROJECT, 2020
** input_postprocessing
** File description:
** test builtin_setenv
*/

/* setenv */
#include <stdlib.h>
/* strdup */
#include <string.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "postprocess/env_var_replace.h"

Test(ipp_env_var_replace, simple_env_var_replace)
{
    const char *var_name = "VAR";
    const char *value = "VALUE";
    char *command = strdup("echo $VAR");

    setenv(var_name, value, 1);
    ipp_env_var_replace(&command);
    cr_assert_str_eq(command, "echo VALUE");
    free(command);
}

Test(ipp_env_var_replace, undefined_variable)
{
    const char *var_name = "VAR";
    char *command = strdup("echo $VAR");

    cr_redirect_stderr();
    unsetenv(var_name);
    ipp_env_var_replace(&command);
    cr_assert_stderr_eq_str("VAR: Undefined variable.\n");
    free(command);
}
