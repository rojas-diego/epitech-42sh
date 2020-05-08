/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** prompt action clear
*/

/* putp */
#include <curses.h>
#include <term.h>

#include "types/shell.h"
#include "types/prompt/effect.h"
#include "proto/prompt/cursor.h"
#include "proto/prompt/display.h"

void prompt_action_clear_term(struct sh *shell)
{
    if (shell->atty) {
        putp(shell->prompt.effect[PROMPT_EFFECT_CLEAR]);
        fflush(0);
        prompt_display(shell);
        fputs(shell->prompt.input, stdout);
        prompt_update_cursor_pos(&(shell->prompt));
    }
}
