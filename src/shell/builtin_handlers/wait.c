/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include <stdio.h>
#include <stdlib.h>

#include "builtins.h"
#include "proto/shell/builtin_handlers.h"

int builtin_wait_handler(
    __attribute__((unused)) struct sh *shell,
    const char * const *argv
)
{
    if (builtins_utils_too_many_arguments(argv, 1)) {
        return (1);
    }
    return (0);
}
