/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action prompt_action_cut_line
*/

#include <stdio.h>

#include "types/shell.h"
#include "types/prompt/effect.h"
#include "proto/prompt/display.h"
#include "proto/prompt/move_cursor_pos.h"
#include "proto/prompt/input/empty.h"
#include "proto/prompt/action/cut_line.h"

void prompt_action_cut_line(struct sh *shell)
{
    if (shell->atty) {
        prompt_move_cursor_pos(&(shell->prompt), 0);
        printf("%*s", (int) shell->prompt.length, "");
        shell->prompt.cursor = shell->prompt.length;
        prompt_move_cursor_pos(&(shell->prompt), 0);
    }
    prompt_input_empty(shell);
}
