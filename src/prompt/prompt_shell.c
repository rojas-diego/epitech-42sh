/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** prompt_shell
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include "types/shell.h"
#include "proto/prompt.h"

/*
** @DESCRIPTION
**   Prints the shell prompt.
** @TODO
**   Handle non tty environments and dont display the prompt.
*/
static void prompt_display(struct sh *shell)
{
    (void)shell;
    printf("$> ");
}

/*
** @DESCRIPTION
**   This function fetches the input from the command line and stores it in
**   the `struct sh`.
*/
static void prompt_fetch(struct sh *shell)
{
    char *buffer = 0;
    size_t length = 0;
    ssize_t response;

    response = getline(&buffer, &length, stdin);
    if (response < 0) {
        shell->active = false;
        free(buffer);
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
    prompt_display(shell);
    prompt_fetch(shell);
}