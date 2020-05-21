/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include <string.h>
#include <stdlib.h>

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"
#include "hasher/type.h"
#include "hasher/insert_data.h"
#include "hasher/get_data.h"
#include "parser_toolbox/argv_length.h"
#include "proto/shell/local_variables.h"
#include "types/local_variables.h"

static _Bool builtin_set_variable(
    struct hasher_s **hasher,
    const char * const *argv,
    size_t *i
)
{
    char *key = strdup(argv[*i]);
    char *data = NULL;
    struct local_var_s *var = NULL;

    if (!key) {
        return (1);
    }
    data = strchr(key, '=');
    if (data) {
        *data = 0;
        var = local_variable_from_data(*hasher, key, &data[1]);
        if (!var) {
            return (0);
        }
        hasher_insert_data_ordered(hasher, key, var);
    }
    return (0);
}

int builtin_set_handler(struct sh *shell, const char * const *argv)
{
    size_t argc = ptb_argv_length(argv);

    if (argc == 1) {
        local_variables_display(
            shell->local_var,
            shell->history.list
        );
        return (0);
    }
    for (size_t i = 1; i < argc; ++i) {
        builtin_set_variable(&shell->local_var, argv, &i);
    }
    return (0);
}
