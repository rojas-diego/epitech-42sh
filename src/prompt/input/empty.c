/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt_input_empty
*/

#include "proto/prompt/input/empty.h"

void prompt_input_empty(struct sh *shell)
{
    for (size_t i = 0; shell->prompt.input[i];) {
        shell->prompt.input[i] = '\0';
        ++i;
    }
    shell->prompt.cursor = 0;
    shell->prompt.length = 0;
}
