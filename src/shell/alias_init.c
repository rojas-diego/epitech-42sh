/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** alias
*/

#include <string.h>

#include "hasher/insert_data.h"

#include "proto/shell/alias.h"

static const int ALIAS_COUNT = 15;

static const struct {
    const char *key;
    const char *data;
} ALIAS_DICT[] = {
    {"cp",      "cp -i"},
    {"egrep",   "egrep --color=auto"},
    {"fgrep",   "fgrep --color=auto"},
    {"grep",    "grep --color=auto"},
    {"l",       "ls -d .* --color=auto"},
    {"ll",      "ls -l --color=auto"},
    {"ls",      "ls --color=auto"},
    {"mv",      "mv -i"},
    {"rm",      "rm -i"},
    {"xzegrep", "xzegrep --color=auto"},
    {"xzfgrep", "xzfgrep --color=auto"},
    {"xzgrep",  "xzgrep --color=auto"},
    {"zegrep",  "zegrep --color=auto"},
    {"zfgrep",  "zfgrep --color=auto"},
    {"zgrep",   "zgrep --color=auto"}
};

struct hasher *shell_alias_hash_create(void)
{
    struct hasher *hash = NULL;
    void *data = NULL;

    for (int i = 0; i < ALIAS_COUNT; ++i) {
        data = (void *) strdup(ALIAS_DICT[i].data);
        if (data == NULL) {
            return (NULL);
        }
        if (hasher_insert_data(
            &hash,
            strdup(ALIAS_DICT[i].key),
            data
        )) {
            return (NULL);
        }
    }
    return (hash);
}
