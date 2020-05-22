/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtins
*/

#ifndef SH_TYPES_BUILTINS_BINDKEY_H_
#define SH_TYPES_BUILTINS_BINDKEY_H_

#include "types/shell.h"

struct bindkey_s {
    void (*func)(struct sh *shell);
    const char *name;
};

#endif /* !SH_TYPES_BUILTINS_BINDKEY_H_ */
