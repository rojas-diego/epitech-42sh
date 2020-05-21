/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt_update_cursor_pos
*/

/* write() */
#include <unistd.h>
/* strlen() */
#include <string.h>

#include "proto/prompt/move_cursor_pos.h"
#include "proto/prompt/input/reprint_input.h"

void prompt_reprint_input(struct prompt *prompt)
{
    size_t save = prompt->cursor;

    prompt->cursor = strlen(prompt->input);
    write(1, prompt->input, prompt->cursor);
    prompt_move_cursor_pos(prompt, save);
}
