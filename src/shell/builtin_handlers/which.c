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

static int builtin_which_display_all_match(const char *binary_name)
{
    const char *path_env = getenv("PATH");
    char *full_path = NULL;

    if (!path_env) {
        return (1);
    }
    for (const char *path = path_iteration(path_env); path;
    path = path_iteration(path_env)) {
        full_path = find_file_in_path(path, binary_name);
        if (!full_path) {
            continue;
        }
        dprintf(1, "%s\n", full_path);
        free(full_path);
        while (path)
            path = path_iteration(path_env);
        return (0);
    }
    return (1);
}

static int builtin_which(struct sh *shell, const char *name)
{
    char *str = NULL;

    str = (char *) hasher_get_data(shell->alias, name);
    if (str) {
        dprintf(1, "%s: \t aliased to ls --color=auto %s\n", name, str);
        return (0);
    }
    str = (char *) hasher_get_data(shell->builtin, name);
    if (str) {
        dprintf(1, "%s: shell built-in command.\n", name);
        return (0);
    }
    if (!builtin_which_display_all_match(name)) {
        return (0);
    }
    dprintf(2, "%s: Command not found.\n", name);
    return (1);
}

int builtin_which_handler(struct sh *shell, const char * const *argv)
{
    int ret = 0;

    if (builtins_utils_too_few_arguments(argv, 1)) {
        return (1);
    }
    for (size_t i = 1; argv[i]; i++) {
        if (strchr(argv[i], '/')) {
            dprintf(2, "%s: Command not found.\n", argv[i]);
            ret = 1;
        } else {
            ret = ret | builtin_which(shell, argv[i]);
        }
    }
    return (ret);
}
