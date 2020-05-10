/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action home
*/

/* putp */
#include <curses.h>
#include <term.h>

#include "types/shell.h"
#include "types/prompt/effect.h"
#include "proto/prompt/action/home.h"

void prompt_action_home(struct sh *shell)
{
    for (; shell->prompt.cursor > 0; --shell->prompt.cursor) {
        putp(shell->prompt.effect[PROMPT_EFFECT_CURSOR_BACKWARD]);
    }
}
