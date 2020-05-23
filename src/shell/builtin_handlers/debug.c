/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include "builtins.h"
#include "proto/shell/builtin_handlers.h"

int builtin_debug_handler(
    struct sh *shell,
    const char * const *argv
)
{
    if (builtins_utils_too_many_arguments(argv, 1)) {
        return (1);
    }
    shell->debug_mode = !shell->debug_mode;
    return (0);
}
