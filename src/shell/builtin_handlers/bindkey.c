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

static void builtin_bindkey_list(void)
{
    printf(BUILTIN_BINDKEY_EDITOR_COMMANDS_WITH_DESCRIPTIONS);
}

static void builtin_bindkey_help(void)
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
    if (!strcmp(argv[1], "-h")) {
        builtin_bindkey_help();
        return (0);
    }
    if (!strcmp(argv[1], "-l")) {
        builtin_bindkey_list();
        return (0);
    }
    return (0);
}
