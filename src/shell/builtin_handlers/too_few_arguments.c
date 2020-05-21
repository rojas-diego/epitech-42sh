/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins too_many_arguments
*/

#include <stdio.h>

#include "parser_toolbox/argv_length.h"

#include "proto/shell/builtin_handlers.h"

int builtins_utils_too_few_arguments(
    const char * const *argv,
    size_t min_arg_count
)
{
    if (ptb_argv_length(argv) - 1 < min_arg_count) {
        dprintf(2, "%s: Too few arguments.\n", argv[0]);
        return (1);
    }
    return (0);
}
