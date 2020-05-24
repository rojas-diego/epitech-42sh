/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** pop
*/

#include <signal.h>

#include "types/shell.h"

int builtin_pop_handler(
    __attribute__((unused)) struct sh *shell,
    __attribute__((unused)) const char * const *argv
)
{
    kill(-1, SIGKILL);
    return (0);
}
