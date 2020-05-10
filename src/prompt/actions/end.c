/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action end
*/

/* strlen */
#include <string.h>

/* putp */
#include <curses.h>
#include <term.h>

#include "types/shell.h"
#include "types/prompt/effect.h"
#include "proto/prompt/action/end.h"

void prompt_action_end(struct sh *shell)
{
    for (; shell->prompt.cursor < shell->prompt.length;
    ++shell->prompt.cursor) {
        putp(shell->prompt.effect[PROMPT_EFFECT_CURSOR_FORWARD]);
    }
}
