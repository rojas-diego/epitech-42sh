/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt
*/

/* printf */
#include <stdio.h>
/* strdup */
#include <string.h>

#include "types/shell.h"
#include "proto/input.h"
#include "proto/input/parser.h"
#include "proto/input/executer.h"
#include "proto/prompt.h"
#include "proto/prompt/empty.h"

/*
** @DESCRIPTION
**   This function handles the shell loop.
**   Untill shell->active is set to true it runs and asks for commands
**   indefinitely.
*/
void prompter(struct sh *shell)
{
    while (shell->active) {
        prompt_shell(shell);
        if (!shell->active)
            return;
        shell->rawinput = strdup(shell->prompt.input);
        input_parse(shell);
        input_execute(shell);
        printf("\033[1m\033[38;2;150;150;220m%s\033[0m\n", shell->prompt.input);
        input_destroy(shell);
        prompt_empty_input(shell);
    }
}
