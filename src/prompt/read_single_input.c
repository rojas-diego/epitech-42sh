/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** read_single_input
*/

/* read */
#include <unistd.h>

#include "proto/prompt/read_single_input.h"

char read_single_input(void)
{
    char character = (char) -1;

    read(STDIN_FILENO, &character, 1);
    return (character);
}
