/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell_bindkey_hash_create
*/

#ifndef SH_SHELL_BINDKEY_H_
#define SH_SHELL_BINDKEY_H_

#include "hasher/type.h"

void builtin_bindkey_list(struct sh *shell, const char * const *argv);
void builtin_bindkey_help(struct sh *shell, const char * const *argv);

struct hasher *shell_bindkey_hash_create(void);

#endif /* !SH_SHELL_BINDKEY_H_ */
