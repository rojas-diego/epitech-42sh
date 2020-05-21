/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include "builtins.h"
#include "types/shell.h"
#include "hasher/type.h"
#include "proto/shell/builtin_handlers.h"
#include "parser_toolbox/argv_length.h"
#include "proto/shell/local_variables.h"

int builtin_at_handler(struct sh *shell, const char * const *argv)
{
    int argc = ptb_argv_length(argv);

    if (argc == 1) {
        local_variables_display(
            shell->local_var,
            shell->history.list
        );
    }
    return (0);
}
