/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** prompt action arrows
*/

/* putp */
#include <curses.h>
#include <term.h>

#include "types/shell.h"

void prompt_action_left(struct sh *shell)
{
    if (shell->prompt.cursor) {
        --shell->prompt.cursor;
        putp(shell->prompt.effect[PROMPT_EFFECT_CURSOR_BACKWARD]);
        fflush(0);
    }
}

void prompt_action_right(struct sh *shell)
{
    if ((shell->prompt.input)[shell->prompt.cursor]) {
        ++shell->prompt.cursor;
        putp(shell->prompt.effect[PROMPT_EFFECT_CURSOR_FORWARD]);
        fflush(0);
    }
}

void prompt_action_up(__attribute__((unused)) struct sh *shell)
{
    return;
}

void prompt_action_down(__attribute__((unused)) struct sh *shell)
{
    return;
}
