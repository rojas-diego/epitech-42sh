/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

static _Bool builtin_set_error_handling(
    struct hasher_s **hasher,
    const char *const *argv,
    size_t *i
)
{
    if (!isalpha(argv[*i][0])) {
        dprintf(2, "set: Variable name must begin with a letter.\n");
        return (1);
    }
    for (size_t j = 0; argv[*i][j] && argv[*i][j] != '='; ++j) {
        if (!isalnum(argv[*i][j])) {
            dprintf(2, "set: Variable name must"
            " contain alphanumeric characters.\n");
            return (1);
        }
    }
    return (builtin_set_variable(hasher, argv, i));
}

int builtin_set_handler(struct sh *shell, const char * const *argv)
{
    size_t argc = ptb_argv_length(argv);
    int status = 0;

    if (argc == 1) {
        local_variables_display(
            shell->local_var,
            shell->history.list
        );
        return (0);
    }
    for (size_t i = 1; i < argc; ++i) {
        status |= builtin_set_error_handling(&shell->local_var, argv, &i);
    }
    return (status);
}
