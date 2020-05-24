/*
** EPITECH PROJECT, 2020
** input_postprocessing
** File description:
** env_var_replace
*/

#include "gnu_source.h"

/* setenv */
#include <stdlib.h>
/* asprintf && dprintf */
#include <stdio.h>
/* size_t */
#include <stddef.h>
#include <string.h>

#include "parser_toolbox/includes.h"
#include "parser_toolbox/unquote.h"
#include "builtin/get_user_home.h"
#include "parser_toolbox/blacklist.h"
#include "proto/exec/magic/parse.h"
#include "types/shell.h"
#include "hasher/get_data.h"
#include "types/local_variables.h"

static const char ENV_VAR_SEP[] = " \t\n\r\f\v\"'";

static char *env_var_getenv(struct sh *shell, char *str)
{
    char *temp = NULL;
    struct local_var_s *var = hasher_get_data(shell->local_var, str);

    if (*str == '{') {
        ptb_unquote(str);
    }
    if (!ptb_blacklist(str, "\\/=&'()[]|{}")) {
        return ((char *) -1);
    }
    if (var && var->type == STRING) {
        return (var->data.string);
    }
    if (var) {
        asprintf(&temp, "%d", var->data.nb);
        return (temp);
    }
    return (getenv(str));
}

static size_t env_var_special_variable(
    struct sh *shell,
    char **env_var,
    char *str
)
{
    size_t length = 0;

    *env_var = NULL;
    if (*str == '?') {
        asprintf(env_var, "%d", shell->last_status);
        for (; str[length] && !ptb_includes(str[length], ENV_VAR_SEP);
            ++length);
        return (length);
    }
    return (0);
}

static size_t env_var_replace_find_env(
    struct sh *shell,
    char **env_var,
    char *str
)
{
    size_t length = env_var_special_variable(shell, env_var, str);
    char save = '\0';

    str[-1] = '\0';
    if (length)
        return (length);
    for (; str[length] && !ptb_includes(str[length], ENV_VAR_SEP); ++length);
    save = str[length];
    str[length] = '\0';
    *env_var = env_var_getenv(shell, str);
    if (*env_var == (char *) -1) {
        dprintf(2, "Illegal variable name.\n");
        return (0);
    }
    if (*env_var == NULL) {
        dprintf(2, "%s: Undefined variable.\n", str);
        return (0);
    }
    str[length] = save;
    return (length);
}

int magic_env_var_replace(struct sh *shell, char **str)
{
    char *save = *str;
    char *env_var = NULL;
    size_t var_name_length = 0;

    for (size_t i = 0; save[i] != '\0'; ++i) {
        if (save[i] != '$' || (i != 0 && save[i - 1] == '\\'))
            continue;
        var_name_length = env_var_replace_find_env(shell, &env_var, save + ++i);
        if (env_var == NULL || env_var == (char *) -1)
            return (1);
        i += var_name_length;
        if (asprintf(str, "%s%s%s", save, env_var, save + i) < 0)
            return (1);
        free(save);
        save = *str;
    }
    return (0);
}
