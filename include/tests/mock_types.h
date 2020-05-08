/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell header file.
*/

#ifndef SH_TEST_SHELL_H_
#define SH_TEST_SHELL_H_

/**/
/* Includes */
/**/

#include <stddef.h>

#include "types/shell.h"

/**/
/* Constants */
/**/

static const char *const MOCK_ENV[] = {
    "PATH=",
    "SHELL=/usr/bin/zsh",
    "PATH=/usr/bin:/usr/local/sbin:/usr/local/bin",
    "OLDPWD=/home"
};

static const struct sh MOCK_SH = {
    .active = true,
    .rawinput = NULL,
    .tokens = NULL,
    .envp = (char **) MOCK_ENV
};

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

#endif
