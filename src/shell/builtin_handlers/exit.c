/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"

int builtin_exit_handler(
    __attribute__((unused)) struct sh *shell,
    const char * const *argv
)
{
    builtin_exit(argv + 1);
    return (0);
}
