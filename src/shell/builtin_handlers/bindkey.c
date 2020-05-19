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
    const char * const *argv
)
{
    if (!argv)
        return (1);
    builtin_bindkey_help();
    return (0);
}
