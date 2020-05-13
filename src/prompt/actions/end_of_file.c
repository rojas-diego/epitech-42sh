/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action end_of_file
*/

#include <stdio.h>

#include "proto/prompt/action/end_of_file.h"

void prompt_action_end_of_file(struct sh *shell)
{
    if (shell->prompt.input[0]) {
        return;
    }
    puts("exit");
    shell->active = false;
}
