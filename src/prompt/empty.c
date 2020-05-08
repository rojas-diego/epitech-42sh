/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** prompt_empty_input
*/

#include "proto/prompt/empty.h"

void prompt_empty_input(struct sh *shell)
{
    for (size_t i = 0; shell->prompt.input[i];) {
        shell->prompt.input[i] = '\0';
        ++i;
    }
    shell->prompt.cursor = 0;
    shell->prompt.length = 0;
}
