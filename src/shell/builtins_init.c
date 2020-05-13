/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include <string.h>

#include "builtins.h"
#include "hasher/insert_data.h"

#include "types/shell.h"
#include "types/builtins.h"
#include "proto/shell/builtin_handlers.h"
#include "proto/shell/builtins.h"

static const int BUILTIN_COUNT = 12;

static const struct {
    const char *key;
    builtin_handler func;
} BUILTINS_DICT[] = {
    {"unsetenv", &builtin_unsetenv_handler},
    {"unalias", NULL},
    {"setenv", &builtin_setenv_handler},
    {"fg", NULL},
    {"exit", &builtin_exit_handler},
    {"echo", &builtin_echo_handler},
    {"cd", &builtin_change_directory_handler},
    {"builtins", &builtin_builtins_handler},
    {"bindkey", NULL},
    {"alias", NULL},
    {"@", NULL},
    {":", NULL},
};

struct hasher *shell_builtin_hash_create(void)
{
    struct hasher *hash = NULL;

    for (int i = 0; i < BUILTIN_COUNT; ++i) {
        if (hasher_insert_data(
            &hash,
            strdup(BUILTINS_DICT[i].key),
            (void *) BUILTINS_DICT[i].func)
        ) {
            return (NULL);
        }
    }
    return (hash);
}
