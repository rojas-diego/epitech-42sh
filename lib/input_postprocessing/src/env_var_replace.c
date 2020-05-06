/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** env_var_replace
*/

#define _GNU_SOURCE
/* setenv() */
#include <stdlib.h>
/* asprintf() && dprintf() */
#include <stdio.h>
/* size_t */
#include <stddef.h>

#include "parser_toolbox/includes.h"

/* */
#include "postprocess/env_var_replace.h"

static const char *ENV_VAR_REPLACE_ERROR_MSG[] = {
    NULL,
    "%s: Undefined variable.\n",
};

static const char ENV_VAR_SEP[] = " \t\n\r\f\v";

static size_t env_var_replace_find_env(
    const char **env_var,
    char *str
)
{
    size_t length = 0;
    char save = '\0';

    for (; str[length] && !ptb_includes(str[length], ENV_VAR_SEP); ++length);
    save = str[length];
    str[length] = '\0';
    *env_var = getenv(str);
    if (*env_var == NULL) {
        dprintf(
            2,
            ENV_VAR_REPLACE_ERROR_MSG[ENV_VAR_REPLACE_UNDEFINED_VAR],
            str
        );
        return ((size_t) -1);
    }
    str[length] = save;
    return (length);
}

enum env_var_replace_status_e ipp_env_var_replace(char **str)
{
    char *save = *str;
    const char *env_var = NULL;
    size_t var_name_length = 0;

    for (int i = 0; save[i] != '\0'; ++i) {
        if (save[i] != '$') {
            continue;
        }
        save[i] = '\0';
        var_name_length = env_var_replace_find_env(&env_var, save + ++i);
        if (env_var == NULL) {
            return (ENV_VAR_REPLACE_UNDEFINED_VAR);
        }
        i += var_name_length;
        asprintf(str, "%s%s%s", save, env_var, save + i);
        free(save);
        save = *str;
    }
    return (ENV_VAR_REPLACE_SUCCESS);
}
