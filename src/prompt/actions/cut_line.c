/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action prompt_action_cut_line
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "types/shell.h"
#include "types/prompt/effect.h"
#include "proto/prompt/display.h"
#include "proto/prompt/move_cursor_pos.h"
#include "proto/prompt/input/empty.h"
#include "proto/prompt/action/clear_line.h"
#include "proto/prompt/action/cut_line.h"

/* TODO: HANDLE malloc */

void prompt_action_cut_line(struct sh *shell)
{
    size_t diff = shell->prompt.length - shell->prompt.cursor;

    if (diff == 0) {
        return (prompt_action_clear_line(shell));
    }
    strncpy(
        shell->prompt.input,
        shell->prompt.input + shell->prompt.cursor,
        shell->prompt.length
    );
    if (shell->atty) {
        prompt_move_cursor_pos(&(shell->prompt), 0);
        printf("%*s", -((int) shell->prompt.length), shell->prompt.input);
        shell->prompt.cursor = shell->prompt.length;
        prompt_move_cursor_pos(&(shell->prompt), 0);
        shell->prompt.length = diff;
    }
}
