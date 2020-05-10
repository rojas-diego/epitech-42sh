/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action prompt_action_clear_line
*/

#include <stdio.h>

#include "proto/prompt/move_cursor_pos.h"
#include "proto/prompt/input/empty.h"
#include "proto/prompt/action/clear_line.h"

void prompt_action_clear_line(struct sh *shell)
{
    if (shell->atty) {
        prompt_move_cursor_pos(&(shell->prompt), 0);
        printf("%*s", (int) shell->prompt.length, "");
        shell->prompt.cursor = shell->prompt.length;
        prompt_move_cursor_pos(&(shell->prompt), 0);
    }
    prompt_input_empty(shell);
}
