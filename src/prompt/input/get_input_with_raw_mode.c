/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** get_input_with_raw_mode
*/

#include "proto/prompt/set_raw_mode.h"
#include "proto/prompt/input/get_input.h"
#include "proto/prompt/input/get_input_with_raw_mode.h"

int get_input_with_raw_mode(struct sh *shell)
{
    term_set_raw_mode(&(shell->prompt.orig_term));
    get_input(shell);
    return (tcsetattr(0, TCSANOW, &(shell->prompt.orig_term)) == -1);
}
