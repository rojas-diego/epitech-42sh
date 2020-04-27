/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** main
*/

#include "types/shell.h"
#include "proto/shell.h"

int main(int argc, char *const *argv, char *const *envp)
{
    struct sh shell = sh_struct_initialise(argc, argv, envp);

    (void)shell;
}
