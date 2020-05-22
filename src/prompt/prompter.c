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

#include "proto/job/do_notification.h"
#include "myerror.h"
/* if (SYNTAX_ERROR && !shell->atty) { break; } */

/* temp header */
#include <wordexp.h>
#include <stdbool.h>
#include "proto/exec/get_argv.h"
#include "proto/exec/simple_exec.h"

/* split_input(shell->rawinput); */

/* temp function */
static void prompt_execution(struct sh *shell)
{
    wordexp_t we = {0};

    if (exec_get_argv(&we, shell->rawinput)) {
        return;
    }
    input_execute(shell);
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
            prompt_input_empty(shell);
            continue;
        }
        history_replace(&(shell->history), &(shell->rawinput));
        history_insert(&(shell->history), shell->rawinput);
        input_parse(shell);
        if (!shell->error)
            prompt_execution(shell);
        input_destroy(shell);
        prompt_input_empty(shell);
        job_do_notification(&(shell->job));
        shell->error = 0;
    }
}
