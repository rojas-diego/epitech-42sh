/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** main
*/

#include "types/shell.h"
#include "proto/shell.h"

/*
** @DESCRIPTION
**   Main.
*/
int main(int argc, char *const *argv, char *const *envp)
{
    struct sh shell = shell_struct_initialise(argc, argv, envp);

    shell_start(&shell);
    return 0;
}
