/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_getenv
*/

#include <stdlib.h>
#include <string.h>

#include "hasher/get_data.h"
#include "types/shell.h"
#include "types/local_variables.h"

static void my_strlwr(char *str)
{
    for (size_t i = 0; str[i]; ++i) {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

char *do_shell_getenv(struct sh *shell, char const *name)
{
    char *value = getenv(name);
    struct local_var_s *var = NULL;
    char *var_path = NULL;

    if (!value) {
        var_path = strdup(name);
        my_strlwr(var_path);
        var = hasher_get_data(shell->local_var, var_path);
        free(var_path);
        if (var && var->type == STRING) {
            return (var->data.string);
        } else {
            return (NULL);
        }
    }
    return (value);
}
