/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell_builtin_hash_create
*/

#ifndef SH_SHELL_BUILTIN_HANDLERS_H_
#define SH_SHELL_BUILTIN_HANDLERS_H_

#include <stddef.h>

#include "types/shell.h"

int builtin_exit_handler(struct sh *shell, const char * const *argv);

int builtin_echo_handler(struct sh *shell, const char * const *argv);

int builtin_setenv_handler(struct sh *shell, const char * const *argv);

int builtin_unsetenv_handler(struct sh *shell, const char * const *argv);

int builtin_builtins_handler(struct sh *shell, const char * const *argv);

int builtin_change_directory_handler(
    struct sh *shell,
    const char * const *argv
);

int builtin_alias_handler(struct sh *shell, const char * const *argv);

int builtin_unalias_handler(struct sh *shell, const char * const *argv);

int builtin_null_command_handler(struct sh *shell, const char * const *argv);

int builtin_bindkey_handler(struct sh *shell, const char * const *argv);

int builtin_source_handler(struct sh *shell, const char * const *argv);

int builtin_fg_handler(struct sh *shell, const char * const *argv);

int builtin_bg_handler(struct sh *shell, const char * const *argv);

int builtin_termname_handler(struct sh *shell, const char * const *argv);

int builtin_wait_handler(struct sh *shell, const char * const *argv);

int builtins_utils_too_many_arguments(
    const char * const *argv,
    size_t max_arg_count
);

int builtins_utils_too_few_arguments(
    const char * const *argv,
    size_t min_arg_count
);

int builtin_jobs_handler(struct sh *shell, const char * const *argv);

int builtin_where_handler(struct sh *shell, const char * const *argv);

int builtin_which_handler(struct sh *shell, const char * const *argv);

int builtin_at_handler(struct sh *shell, const char * const *argv);

int builtin_unset_handler(struct sh *shell, const char * const *argv);

int builtin_set_handler(struct sh *shell, const char * const *argv);

int builtin_debug_handler(struct sh *shell, const char * const *argv);

int builtin_history_handler(struct sh *shell, const char * const *argv);

#endif /* !SH_SHELL_BUILTIN_HANDLERS_H_ */
