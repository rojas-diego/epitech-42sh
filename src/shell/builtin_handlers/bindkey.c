/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include "builtins.h"
#include "types/shell.h"
#include "proto/shell/builtin_handlers.h"

void builtin_bindkey_help(void)
{
    
}

int builtin_bindkey_handler(
    __attribute__((unused)) struct sh *shell,
    __attribute__((unused)) const char * const *argv
)
{
    if (!argv)
        return (1);
    if (argv[1] && strcmp(argv[1], "-h"))
        builtin_bindkey_help();
    return (0);
}
