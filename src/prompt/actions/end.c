/*
** EPITECH PROJECT, 2019
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

void prompt_action_end(struct sh *shell)
{
    size_t len = strlen(shell->prompt.input);

    for (; shell->prompt.cursor < len; ++shell->prompt.cursor) {
        putp(shell->prompt.effect[PROMPT_EFFECT_CURSOR_BACKWARD]);
    }
    fflush(0);
}
