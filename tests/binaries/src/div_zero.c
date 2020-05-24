/*
** EPITECH PROJECT, 2020
** div_zero
** File description:
** main
*/

#include <signal.h>

int main(void)
{
    raise(SIGFPE);
    return (0);
}
