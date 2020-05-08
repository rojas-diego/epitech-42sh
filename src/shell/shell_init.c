/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** init
*/

#include <unistd.h>
#include <string.h>

#include "types/shell.h"
#include "proto/shell.h"

int term_init(struct sh *shell);

/* TODO: parse av: if fd replace STDIN_FILENO in isatty by fildes */

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
    (*this).atty = isatty(STDIN_FILENO);
    (*this).prompt.cursor = 0;
    memset((*this).prompt.input, 0, 8192);
    if (term_init(this)) {
        return;
    }
}
