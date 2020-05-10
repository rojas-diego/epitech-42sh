/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action interrupt
*/

#include <stdio.h>

#include "types/shell.h"
#include "types/prompt/effect.h"
#include "proto/prompt/input/empty.h"
#include "proto/prompt/display.h"
#include "proto/prompt/action/interrupt.h"

void prompt_action_interrupt(struct sh *shell)
{
    puts("^C");
    prompt_input_empty(shell);
    prompt_display(shell);
}
