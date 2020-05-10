/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** read_single_input
*/

/* read */
#include <unistd.h>

#include "proto/prompt/input/read_single_input.h"

enum get_input_e read_single_input(char *character)
{
    ssize_t total_read = read(STDIN_FILENO, character, 1);

    if (total_read == -1) {
        return (GET_INPUT_READ_FAIL);
    }
    if (total_read == 0) {
        *character = -1;
    }
    return (GET_INPUT_CONTINUE);
}
