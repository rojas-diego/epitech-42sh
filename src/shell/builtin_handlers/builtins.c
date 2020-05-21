/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include <stdio.h>

#include "hasher/type.h"

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"

int builtin_builtins_handler(struct sh *shell, const char * const *argv)
{
    if (builtins_utils_too_many_arguments(argv, 0)) {
        return (1);
    }
    for (struct hasher *builtin = shell->builtin; builtin != NULL;
    builtin = builtin->next) {
        dprintf(1, "%s\n", builtin->key);
    }
    return (0);
}
