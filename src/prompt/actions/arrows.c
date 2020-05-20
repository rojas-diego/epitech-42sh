/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action arrows
*/

/* putp */
#include <curses.h>
#include <string.h>
#include <term.h>

#include "dnode.h"

#include "proto/prompt/action/left.h"
#include "proto/prompt/action/right.h"
#include "proto/prompt/action/down.h"
#include "proto/prompt/action/up.h"
#include "proto/prompt/action/clear_line.h"
#include "proto/prompt/input/add_string.h"
#include "proto/prompt/history.h"

void prompt_action_left(struct sh *shell)
{
    if (shell->prompt.cursor) {
        --shell->prompt.cursor;
        putp(shell->prompt.effect[PROMPT_EFFECT_CURSOR_BACKWARD]);
    }
}

void prompt_action_right(struct sh *shell)
{
    if ((shell->prompt.input)[shell->prompt.cursor]) {
        ++shell->prompt.cursor;
        putp(shell->prompt.effect[PROMPT_EFFECT_CURSOR_FORWARD]);
    }
}

void prompt_action_up(struct sh *shell)
{
    if (!shell->history.curr) {
        shell->history.curr = shell->history.list;
        strcpy(shell->history.current_input, shell->prompt.input);
    } else if (shell->history.curr->next) {
        shell->history.curr = shell->history.curr->next;
    }
    prompt_action_clear_line(shell);
    if (shell->history.curr) {
        prompt_input_add_string(shell, (char *) shell->history.curr->data);
    } else {
        prompt_input_add_string(shell, shell->history.current_input);
    }
}

void prompt_action_down(struct sh *shell)
{
    if (shell->history.curr) {
        shell->history.curr = shell->history.curr->prev;
    }
    prompt_action_clear_line(shell);
    if (shell->history.curr) {
        prompt_input_add_string(shell, (char *) shell->history.curr->data);
    } else {
        prompt_input_add_string(shell, shell->history.current_input);
    }
}
