/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** prompt
*/

#include "types/shell.h"
#include "proto/input.h"
#include "proto/input/parser.h"
#include "proto/input/executer.h"
#include "proto/prompt.h"
#include "proto/prompt/empty.h"

/*
input_parse(shell);
input_execute(shell);
*/

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
        prompt_empty_input(shell);
    }
}
