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
#include "parser_toolbox/whitelist.h"
#include "parser_toolbox/range.h"

/* */
#include "builtin/setenv.h"

static const char *SETENV_ERROR_MSG[] = {
    NULL,
    "setenv: Too many arguments.\n",
    "setenv: Variable name must contain alphanumeric characters.\n",
    "setenv: Variable name must begin with a letter.\n",
};

enum builtin_setenv_e builtin_setenv(const char * const *argv)
{
    if (!argv[0]) {
        builtin_display_env();
        return (SETENV_SUCCESS);
    }
    if (ptb_argv_length(argv) > 2) {
        dprintf(2, "%s", SETENV_ERROR_MSG[SETENV_TOO_MANY_ARGS]);
        return (SETENV_TOO_MANY_ARGS);
    }
    if (!ptb_whitelist_alphanum(argv[0])) {
        dprintf(2, "%s", SETENV_ERROR_MSG[SETENV_ALPHANUM_ONLY]);
        return (SETENV_ALPHANUM_ONLY);
    }
    if (ptb_range(argv[0][0], '1', '9')) {
        dprintf(2, "%s", SETENV_ERROR_MSG[SETENV_MUST_BEGIN_WITH_A_LETTER]);
        return (SETENV_MUST_BEGIN_WITH_A_LETTER);
    }
    return (setenv(argv[0], argv[1] ? argv[1] : "", 1) == -1 ?
        SETENV_ALLOCATION_FAIL : SETENV_SUCCESS
    );
}
