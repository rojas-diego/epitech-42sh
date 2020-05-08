/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action delete
*/

/* fputs */
#include <stdio.h>

/* strlen */
#include <string.h>

#include "parser_toolbox/remove_char.h"

#include "types/shell.h"
#include "types/prompt/effect.h"
#include "proto/prompt/cursor.h"

void prompt_action_delete(struct sh *shell)
{
    if (!(shell->prompt.input)[0]
    || shell->prompt.cursor >= strlen(shell->prompt.input)) {
        return;
    }
    ptb_remove_char(shell->prompt.input, shell->prompt.cursor);
    if (shell->atty) {
        fputs(shell->prompt.input + shell->prompt.cursor, stdout);
        fputs(" ", stdout);
        shell->prompt.cursor -= 1;
        prompt_update_cursor_pos(&(shell->prompt));
        shell->prompt.cursor += 1;
    }
}
