/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action prompt_action_clear_term
*/

/* putp */
#include <curses.h>
#include <term.h>

#include "proto/prompt/update_cursor_pos.h"
#include "proto/prompt/display.h"
#include "proto/prompt/action/clear_term.h"

void prompt_action_clear_term(struct sh *shell)
{
    if (shell->atty) {
        putp(shell->prompt.effect[PROMPT_EFFECT_CLEAR]);
        prompt_display(shell);
        fputs(shell->prompt.input, stdout);
        prompt_update_cursor_pos(&(shell->prompt));
    }
}
