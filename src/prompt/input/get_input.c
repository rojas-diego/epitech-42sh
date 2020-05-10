/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** get_input
*/

/* free */
#include <stdlib.h>
/* fflush */
#include <stdio.h>

#include "proto/prompt/rewrite_color_command.h"
#include "proto/prompt/input/read_single_input.h"
#include "proto/prompt/input/add_string.h"
#include "proto/prompt/input/wait_input.h"
#include "proto/prompt/input/get_extended_input.h"
#include "proto/prompt/input/get_input.h"

static enum get_input_e add_input_or_execute_action(
    struct sh *shell,
    char character
)
{
    enum get_input_e status = GET_INPUT_CONTINUE;
    char *buffer = NULL;

    if (character == '\n' || character == 0x00
    || (!shell->prompt.length && character == 0x04)) {
        shell->active = !(character == 0x04);
        rewrite_color_command(shell);
        return (GET_INPUT_END_OF_TRANSMISSION);
    }
    buffer = get_extended_input(shell, &status, character);
    if (status != GET_INPUT_CONTINUE) {
        if (buffer)
            free(buffer);
        return (status);
    }
    if (buffer) {
        prompt_input_add_string(shell, buffer);
        free(buffer);
    }
    return (fflush(stdout) == -1 ? GET_INPUT_FLUSH_FAIL : GET_INPUT_CONTINUE);
}

enum get_input_e get_input(struct sh *shell)
{
    enum get_input_e status = GET_INPUT_CONTINUE;
    char character = -1;

    while (status == GET_INPUT_CONTINUE) {
        if (wait_input() == -1) {
            return (GET_INPUT_WAIT_FAIL);
        }
        status = read_single_input(&character);
        if (character == -1) {
            if (shell->atty) {
                continue;
            }
            break;
        }
        status = add_input_or_execute_action(shell, character);
    }
    return (status);
}
