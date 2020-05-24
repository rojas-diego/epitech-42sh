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

#include "types/builtins/bindkey.h"
#include "proto/shell/bindkey.h"

void builtin_bindkey_bind(
    __attribute__((unused)) struct sh *shell,
    __attribute__((unused)) const char * const *argv
);

void builtin_bindkey_display_settings(
    struct sh *shell,
    __attribute__((unused)) const char * const *argv
);

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
    printf("%s%s", BUILTIN_BINDKEY_HELP, BUILTIN_BINDKEY_HELP_PART_2);
}

void builtin_bindkey_display_settings(
    struct sh *shell,
    __attribute__((unused)) const char * const *argv
)
{
    int i;

    for (struct hasher_s *this = shell->bindkey; this; this = this->next) {
        printf("\"");
        for (i = 0; this->key[i]; i++) {
            if (isprint(this->key[i]))
                printf("%c", this->key[i]);
        }
        printf("\"%*s", 13 - i, "");
        printf("->  %s\n", ((struct bindkey_s *) this->data)->name);
    }
}

void builtin_bindkey_bind(
    __attribute__((unused)) struct sh *shell,
    __attribute__((unused)) const char * const *argv
)
{
    return;
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
