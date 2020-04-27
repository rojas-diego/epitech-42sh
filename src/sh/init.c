/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** init
*/

#include "types/shell.h"
#include "proto/shell.h"

/*
** @DESCRIPTION
**   Initialises a local `struct sh` and inits all of its members.
*/
struct sh sh_struct_initialise(int argc, char *const *argv, char *const *envp)
{
    struct sh this;

    (void)argc;
    (void)argv;
    this.envp = envp;
    return this;
}