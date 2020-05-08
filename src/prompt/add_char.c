/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action add_char
*/

#include <stdio.h>

#include "parser_toolbox/add_char.h"

#include "types/shell.h"
#include "types/prompt/effect.h"
#include "proto/prompt/cursor.h"

void prompt_add_char(struct sh *shell, char c)
{
    ptb_add_char(shell->prompt.input, shell->prompt.cursor, c);
    if (shell->atty) {
        fputs(shell->prompt.input + shell->prompt.cursor, stdout);
        shell->prompt.cursor += 1;
        prompt_update_cursor_pos(&(shell->prompt));
    } else {
        shell->prompt.cursor += 1;
    }
}
