/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hasher/get_data.h"
#include "path_iteration.h"
#include "find_file_in_path.h"

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"

static int builtin_where_display_all_match(const char *binary_name)
{
    const char *path_env = getenv("PATH");
    char *full_path = NULL;
    int ret = 1;

    if (!path_env) {
        return (ret);
    }
    for (const char *path = path_iteration(path_env); path;
    path = path_iteration(path_env)) {
        full_path = find_file_in_path(path, binary_name);
        if (!full_path) {
            continue;
        }
        dprintf(1, "%s\n", full_path);
        free(full_path);
        ret = 0;
    }
    return (ret);
}

static int builtin_where(struct sh *shell, const char *name)
{
    char *str = NULL;
    int ret = 1;

    str = (char *) hasher_get_data(shell->alias, name);
    if (str) {
        dprintf(1, "%s is aliased to %s\n", name, str);
        ret = 0;
    }
    str = (char *) hasher_get_data(shell->builtin, name);
    if (str) {
        dprintf(1, "%s is a shell built-in\n", name);
        ret = 0;
    }
    if (!builtin_where_display_all_match(name)) {
        ret = 0;
    }
    return (ret);
}

int builtin_where_handler(struct sh *shell, const char * const *argv)
{
    int ret = 0;

    if (builtins_utils_too_few_arguments(argv, 1)) {
        return (1);
    }
    for (size_t i = 1; argv[i]; i++) {
        if (strchr(argv[i], '/')) {
            dprintf(2, "%s: / in command makes no sense\n", argv[0]);
            ret = 1;
        } else {
            ret = ret | builtin_where(shell, argv[i]);
        }
    }
    return (ret);
}
