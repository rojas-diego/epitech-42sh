/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** check debug mode
*/

#include <stdbool.h>
#include <string.h>

bool check_debug_mode(char *const *av)
{
    if (!av[1])
        return (false);
    else if (!strcmp(av[1], "--debug-mode"))
        return (true);
    else
        return (false);
}