/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action interrupt
*/

#include <stdio.h>

#include "types/shell.h"
#include "types/prompt/effect.h"
#include "proto/prompt/empty.h"
#include "proto/prompt/display.h"

void prompt_action_interrupt(struct sh *shell)
{
    puts("^C");
    prompt_empty_input(shell);
    prompt_display(shell);
}
