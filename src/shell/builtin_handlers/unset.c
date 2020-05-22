/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

/* free */
#include <stdlib.h>

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"
#include "hasher/pop.h"
#include "types/local_variables.h"

int builtin_unset_handler(struct sh *shell, const char * const *argv)
{
    struct hasher_s *node = NULL;
    struct local_var_s *var = NULL;

    for (size_t i = 1; argv[i]; ++i) {
        node = hasher_pop(&shell->local_var, argv[i]);
        if (!node) {
            continue;
        }
        var = node->data;
        if (var->type == STRING) {
            free(var->data.string);
        }
        free(var);
        free(node->key);
        free(node);
    }
    return (0);
}
