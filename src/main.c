/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** main
*/

#include "proto/shell.h"

/*
** @DESCRIPTION
**   Main.
*/
int main(int argc, const char **argv, char * const *envp)
{
    struct sh shell;

    if (shell_struct_initialise(&shell, argc, argv, envp)) {
        return (84);
    }
    if (shell_start(&shell)) {
        return (84);
    }
    shell_destroy(&shell);
    return (0);
}
