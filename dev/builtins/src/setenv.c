/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** builtin_setenv
*/

/* dprintf() */
#include <stdio.h>
/* setenv() */
#include <stdlib.h>

#include "builtin/display_env.h"
#include "parser_toolbox/argv_length.h"

/* */
#include "builtin/setenv.h"

static const char *SETENV_ERROR_MESSAGES[] = {
    NULL,
    "setenv: Too many arguments.\n",
    "setenv: Variable name must contain alphanumeric characters.\n",
    "setenv: Variable name must begin with a letter.\n",
}

enum builtin_setenv_e builtin_setenv(const char * const *argv)
{
    if (!argv[0]) {
        builtin_display_env();
        return (SETENV_SUCCESS);
    }
    if (ptb_argv_length(argv) > 2) {
        dprintf(2, SETENV_ERROR_MESSAGES[SETENV_TOO_MANY_ARGS]);
        return (SETENV_TOO_MANY_ARGS);
    }
    if (!ptb_whitelist_alphanum(argv[0])) {
        dprintf(2, SETENV_ERROR_MESSAGES[SETENV_ALPHANUM_ONLY]);
        return (SETENV_ALPHANUM_ONLY);
    }
    if (!ptb_whitelist_digit(argv[0])) {
        dprintf(2, SETENV_ERROR_MESSAGES[SETENV_MUST_BEGIN_WITH_A_LETTER]);
        return (SETENV_MUST_BEGIN_WITH_A_LETTER);
    }
    if (setenv(argv[0], argv[1] ? argv[1] : "", 1) == -1) {
        dprintf(2, "ENOMEM\n");
        return (SETENV_ALLOCATION_FAIL);
    }
    return (SETENV_SUCCESS);
}
