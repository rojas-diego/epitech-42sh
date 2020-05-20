/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt_display
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proto/shell.h"
#include "proto/prompt/display.h"
#include "parser_toolbox/strrep.h"

/*
** @DESCRIPTION
**   Prints the shell prompt.
*/
int prompt_display(__attribute__((unused)) struct sh *shell)
{
    const char *dir = getenv("PWD");
    const char *user = getenv("USER");
    const char *home = getenv("HOME");
    char *host = getenv("HOSTNAME");

    if (host) {
        host = ptb_strrep(strdup(host), '.', '\0');
        if (!host)
            return (EXIT_FAILURE);
    }
    if (dir && home && !strcmp(dir, home))
        dir = "/~";
    dir = dir ? strrchr(dir, '/') : dir;
    printf("\033[38;2;150;220;150m""[%s@%s %s]%s\033[0m",
        user ? user : "", host ? host: "", dir ? dir : "", "$> ");
    fflush(stdout);
    if (host)
        free(host);
    return (EXIT_SUCCESS);
}
