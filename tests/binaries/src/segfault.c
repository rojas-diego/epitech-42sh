/*
** EPITECH PROJECT, 2020
** segfault
** File description:
** main
*/

#include <signal.h>

int main(void)
{
    raise(SIGSEGV);
    return (0);
}
