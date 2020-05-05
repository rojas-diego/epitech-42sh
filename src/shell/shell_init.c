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
void shell_struct_initialise(
    struct sh *this,
    __attribute__((unused)) int ac,
    __attribute__((unused)) char *const *av,
    char *const *ep
)
{
    (*this).envp = ep;
    (*this).rawinput = 0;
    (*this).active = true;
}
