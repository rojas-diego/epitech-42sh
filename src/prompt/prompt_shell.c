/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt_shell
*/

#include "proto/prompt/display.h"
#include "proto/prompt/input/get_input.h"
#include "proto/prompt/input/get_input_with_raw_mode.h"
#include "proto/prompt.h"

/*
** @DESCRIPTION
**   This function both displays the shell prompt and fetches the
**   input from the terminal.
*/
void prompt_shell(struct sh *shell)
{
    prompt_display(shell);
    if (shell->atty) {
        get_input_with_raw_mode(shell);
    } else {
        get_input(shell);
    }
}
