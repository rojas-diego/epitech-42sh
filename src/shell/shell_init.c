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
struct sh shell_struct_initialise(int ac, char *const *av, char *const *ep)
{
    struct sh this;

    (void)ac;
    (void)av;
    this.envp = ep;
    this.rawinput = 0;
    this.active = true;
    return this;
}