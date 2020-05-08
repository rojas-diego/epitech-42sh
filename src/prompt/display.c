/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** prompt_display
*/

#include <stdio.h>
#include <unistd.h>

#include "proto/shell.h"
#include "proto/prompt/display.h"

/*
** @DESCRIPTION
**   Prints the shell prompt.
** @TODO
**   Handle non tty environments and dont display the prompt.
*/
void prompt_display(__attribute__((unused)) struct sh *shell)
{
    if (shell->atty) {
        fputs("$> ", stdout);
        fflush(STDIN_FILENO);
    }
}
