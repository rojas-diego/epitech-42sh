/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt_shell
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parser_toolbox/consts.h"
#include "parser_toolbox/whitelist.h"

#include "proto/prompt/display.h"
#include "proto/prompt/input/get_input.h"
#include "proto/prompt/input/get_input_with_raw_mode.h"
#include "proto/prompt.h"

/*
** @DESCRIPTION
**   This function fetches the input from the command line and stores it in
**   the `struct sh`.
*/
static void prompt_fetch(struct sh *shell)
{
    char *buffer = NULL;
    size_t length = 0;
    ssize_t response;

    response = getline(&buffer, &length, stdin);
    if (response <= 0 || ptb_whitelist(buffer, PTB_WHITESPACES)) {
        if (response < 0) {
            shell->active = false;
        }
        if (buffer)
            free(buffer);
        buffer = NULL;
    } else if (buffer[response - 1] == '\n') {
        buffer[response - 1] = '\0';
    }
    shell->rawinput = buffer;
}

/*
** @DESCRIPTION
**   This function both displays the shell prompt and fetches the
**   input from the terminal.
*/
void prompt_shell(struct sh *shell)
{
    if (shell->atty) {
        prompt_display(shell);
        get_input_with_raw_mode(shell);
        if (ptb_whitelist(shell->prompt.input, PTB_WHITESPACES)) {
            shell->rawinput = NULL;
            return;
        }
        shell->rawinput = strdup(shell->prompt.input);
    } else {
        prompt_fetch(shell);
    }
}
