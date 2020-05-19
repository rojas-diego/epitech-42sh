/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompter
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
#include "proto/prompt/history.h"
#include "proto/prompt/input/empty.h"

/* if (SYNTAX_ERROR && !shell->atty) { break; } */

/* temp header */
#include <wordexp.h>
#include "proto/exec/get_argv.h"
#include "proto/exec/simple_exec.h"

/* temp function */
static void prompt_execution(struct sh *shell)
{
    wordexp_t we;

    if (exec_get_argv(&we, shell->rawinput)) {
        return;
    }
    input_execute(shell);
    //split_input(shell->rawinput);
    simple_exec(shell, &we);
    wordfree(&we);
}

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
        if (!shell->active) {
            return;
        }
        if (shell->rawinput == NULL) {
            continue;
        }
        history_insert(&(shell->history), shell->rawinput);
        input_parse(shell);
        prompt_execution(shell);
        input_destroy(shell);
        prompt_input_empty(shell);
    }
}
