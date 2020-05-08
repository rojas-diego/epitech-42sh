/*
** EPITECH PROJECT, 2020
** builtins
** File description:
** builtin_setenv
*/

#ifndef BUILTIN_SETENV_H_
#define BUILTIN_SETENV_H_

enum builtin_setenv_e {
    SETENV_SUCCESS = 0,
    SETENV_TOO_MANY_ARGS = 1,
    SETENV_ALPHANUM_ONLY = 2,
    SETENV_MUST_BEGIN_WITH_A_LETTER = 3,
    SETENV_ALLOCATION_FAIL
};

enum builtin_setenv_e builtin_setenv(const char * const *argv);

#endif /* !BUILTIN_SETENV_H_ */
