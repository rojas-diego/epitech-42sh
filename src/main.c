/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** main
*/

#include "types/shell.h"
#include "proto/shell.h"

/*
** @DESCRIPTION
**   Main.
*/
int main(int argc, char * const *argv, char * const *envp)
{
    struct sh shell;

    shell_struct_initialise(&shell, argc, argv, envp);
    shell_start(&shell);
    return (0);
}
