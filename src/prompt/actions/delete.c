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
#include "proto/prompt/update_cursor_pos.h"
#include "proto/prompt/action/delete.h"

void prompt_action_delete(struct sh *shell)
{
    if (!shell->prompt.length || shell->prompt.cursor >= shell->prompt.length) {
        return;
    }
    shell->prompt.length -= 1;
    ptb_remove_char(shell->prompt.input, shell->prompt.cursor);
    if (shell->atty) {
        fputs(shell->prompt.input + shell->prompt.cursor, stdout);
        fputs(" ", stdout);
        shell->prompt.cursor -= 1;
        prompt_update_cursor_pos(&(shell->prompt));
        shell->prompt.cursor += 1;
    }
}
