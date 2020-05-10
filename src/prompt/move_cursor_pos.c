/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt_move_cursor_pos
*/

/* strlen */
#include <string.h>

/* putp */
#include <curses.h>
#include <term.h>

#include "types/prompt.h"
#include "proto/prompt/move_cursor_pos.h"

void prompt_move_cursor_pos(struct prompt *prompt, size_t new_pos)
{
    ssize_t diff = (ssize_t) new_pos - (ssize_t) prompt->cursor;
    const char *effect = NULL;

    if (diff < 0) {
        diff = -diff;
        effect = prompt->effect[PROMPT_EFFECT_CURSOR_BACKWARD];
    } else {
        effect = prompt->effect[PROMPT_EFFECT_CURSOR_FORWARD];
    }
    for (ssize_t size = 0; size < diff; ++size) {
        putp(effect);
    }
    prompt->cursor = new_pos;
}
