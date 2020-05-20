/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "hasher/type.h"
#include "builtins.h"
#include "constants/prompt/builtins/private_bindkey.h"
#include "proto/shell/builtin_handlers.h"

void builtin_bindkey_list(
    __attribute__((unused)) struct sh *shell,
    __attribute__((unused)) const char * const *argv
)
{
    printf(BUILTIN_BINDKEY_EDITOR_COMMANDS_WITH_DESCRIPTIONS);
}

void builtin_bindkey_help(
    __attribute__((unused)) struct sh *shell,
    __attribute__((unused)) const char * const *argv
)
{
    printf(BUILTIN_BINDKEY_HELP);
}

void builtin_bindkey_display_settings(
    struct sh *shell,
    __attribute__((unused)) const char * const *argv
)
{
    for (struct hasher *this = shell->bindkey; this; this = this->next) {
        printf("\"");
        for (int i = 0; this->key[i]; i++) {
            if (isprint(this->key[i]))
                printf("%c", this->key[i]);
        }
        printf("\"");
        printf(" -> ");
        printf("\n");
    }
}

void builtin_bindkey_bind(
    struct sh *shell,
    const char * const *argv
)
{
    //hasher_insert_data_ordered(shell->bindkey, );
}

int builtin_bindkey_handler(struct sh *shell, const char * const *argv)
{
    if (!argv[1]) {
        builtin_bindkey_display_settings(shell, argv);
        return (0);
    }
    for (int i = 0; BINDKEY_FLAG[i].flag; i++) {
        if (!strcmp(BINDKEY_FLAG[i].flag, argv[1])) {
            BINDKEY_FLAG[i].function(shell, argv);
            return (0);
        }
    }
    if (!argv[2]) {
        builtin_bindkey_help(shell, argv);
    } else {
        builtin_bindkey_bind(shell, argv);
    }
    return (0);
}
