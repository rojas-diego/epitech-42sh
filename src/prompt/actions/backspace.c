/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** prompt action backspace
*/

/* putp */
#include <curses.h>
#include <term.h>

#include "parser_toolbox/remove_char.h"

#include "types/shell.h"
#include "types/prompt/effect.h"
#include "proto/prompt/cursor.h"

void prompt_action_backspace(struct sh *shell)
{
    if (!(shell->prompt.input)[0] || !shell->prompt.cursor) {
        return;
    }
    shell->prompt.cursor -= !!shell->prompt.cursor;
    ptb_remove_char(shell->prompt.input, shell->prompt.cursor);
    if (shell->atty) {
        putp(shell->prompt.effect[PROMPT_EFFECT_CURSOR_BACKWARD]);
        fputs(shell->prompt.input + shell->prompt.cursor, stdout);
        fputs(" ", stdout);
        --shell->prompt.cursor;
        prompt_update_cursor_pos(&(shell->prompt));
        ++shell->prompt.cursor;
    }
}
