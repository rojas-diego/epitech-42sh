/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** get_input
*/

/* printf */
#include <stdio.h>

/* putp */
#include <curses.h>
#include <term.h>

#include "proto/prompt/rewrite_color_command.h"

void rewrite_color_command(struct sh *shell)
{
    for (size_t i = 0; i < shell->prompt.cursor; ++i) {
        putp(shell->prompt.effect[PROMPT_EFFECT_CURSOR_BACKWARD]);
    }
    printf("\033[1m\033[38;2;150;200;0m%s\033[0m\n", shell->prompt.input);
}
