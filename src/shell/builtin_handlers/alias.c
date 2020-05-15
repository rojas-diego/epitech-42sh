/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include <stdio.h>

#include "hasher/pop.h"
#include "hasher/destroy.h"

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"

/* check_alias() */
int builtin_alias_handler(
    struct sh *shell,
    const char * const *argv
)
{
    if (!argv[1]) {
        for (struct hasher *alias = shell->alias; alias != NULL;
        alias = alias->next) {
            dprintf(1, "%s\n", alias->key);
        }
    } else if (!argv[2]) {
    } else {
        dprintf(2, "%s: Too many arguments.\n", argv[0]);
        return (1);
    }
    return (0);
}

int builtin_unalias_handler(
    struct sh *shell,
    const char * const *argv
)
{
    struct hasher *poped = NULL;

    if (!argv[1]) {
        dprintf(2, "%s: Too few arguments.\n", argv[0]);
        return (1);
    }
    for (size_t i = 1; argv[i]; ++i) {
        poped = hasher_pop(&shell->alias, argv[i]);
        if (poped) {
            hasher_destroy(poped, true, true);
        }
    }
    return (0);
}
