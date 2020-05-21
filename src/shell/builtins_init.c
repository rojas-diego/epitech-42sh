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

static const int BUILTIN_COUNT = 20;

static const struct {
    const char *key;
    builtin_handler func;
} BUILTINS_DICT[] = {
    {"which", &builtin_which_handler},
    {"where", &builtin_where_handler},
    {"unsetenv", &builtin_unsetenv_handler},
    {"unset", &builtin_unset_handler},
    {"unalias", &builtin_unalias_handler},
    {"termname", &builtin_termname_handler},
    {"source", &builtin_source_handler},
    {"setenv", &builtin_setenv_handler},
    {"set", &builtin_set_handler},
    {"jobs", &builtin_jobs_handler},
    {"fg", &builtin_fg_handler},
    {"exit", &builtin_exit_handler},
    {"echo", &builtin_echo_handler},
    {"cd", &builtin_change_directory_handler},
    {"builtins", &builtin_builtins_handler},
    {"bindkey", &builtin_bindkey_handler},
    {"bg", &builtin_bg_handler},
    {"alias", &builtin_alias_handler},
    {"@", &builtin_at_handler},
    {":", &builtin_null_command_handler},
};

struct hasher_s *shell_builtin_hash_create(void)
{
    struct hasher_s *hash = NULL;

    for (int i = 0; i < BUILTIN_COUNT; ++i) {
        if (hasher_insert_data(
            &hash,
            strdup(BUILTINS_DICT[i].key),
            (void *) &BUILTINS_DICT[i].func)
        ) {
            return (NULL);
        }
    }
    return (hash);
}
