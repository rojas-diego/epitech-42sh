/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell_builtin_hash_create
*/

#ifndef SH_SHELL_BUILTIN_HANDLERS_H_
#define SH_SHELL_BUILTIN_HANDLERS_H_

int builtin_exit_handler(struct sh *shell, const char * const *argv);
int builtin_echo_handler(struct sh *shell, const char * const *argv);
int builtin_setenv_handler(struct sh *shell, const char * const *argv);
int builtin_unsetenv_handler(struct sh *shell, const char * const *argv);
int builtin_builtins_handler(struct sh *shell, const char * const *argv);
int builtin_change_directory_handler(
    struct sh *shell,
    const char * const *argv
);

#endif /* !SH_SHELL_BUILTIN_HANDLERS_H_ */
