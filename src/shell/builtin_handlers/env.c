/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"

int builtin_setenv_handler(
    __attribute__((unused)) struct sh *shell,
    const char * const *argv
)
{
    builtin_setenv(argv + 1);
    return (0);
}

int builtin_unsetenv_handler(
    __attribute__((unused)) struct sh *shell,
    const char * const *argv
)
{
    builtin_unsetenv(argv + 1);
    return (0);
}
