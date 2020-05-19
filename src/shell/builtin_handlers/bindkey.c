/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include "builtins.h"
#include "types/shell.h"
#include "constants/prompt/builtins/private_bindkey.h"
#include "proto/shell/builtin_handlers.h"
#include <string.h>
#include <stdio.h>

void builtin_bindkey_list(void)
{
    printf(BUILTIN_BINDKEY_EDITOR_COMMANDS_WITH_DESCRIPTIONS);
}

void builtin_bindkey_help(void)
{
    printf(BUILTIN_BINDKEY_HELP);
}

int builtin_bindkey_handler(
    __attribute__((unused)) struct sh *shell,
    const char * const *argv
)
{
    if (!argv[1]) {
        builtin_bindkey_help();
        return (0);
    }
    for (int i = 0; BINDKEY_FLAG[i].flag; i++) {
        if (!strcmp(BINDKEY_FLAG[i].flag, argv[1]))
            BINDKEY_FLAG[i].function();
    }
    return (0);
}
