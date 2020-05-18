/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** init
*/

#include <unistd.h>
#include <string.h>

#include "proto/shell.h"
#include "proto/shell/builtins.h"
#include "proto/shell/alias.h"
#include "proto/shell/term_init.h"
#include "proto/shell/bindkey.h"

/* TODO: parse av: if fd replace STDIN_FILENO in isatty by fildes */

/*
** @DESCRIPTION
**   Initialises a local `struct sh` and inits all of its members.
*/
int shell_struct_initialise(
    struct sh *this,
    __attribute__((unused)) int ac,
    __attribute__((unused)) char *const *av,
    char *const *ep
)
{
    (*this).error = ER_NONE;
    (*this).tokens = 0;
    (*this).envp = ep;
    (*this).rawinput = 0;
    (*this).active = true;
    (*this).atty = isatty(STDIN_FILENO);
    (*this).prompt.cursor = 0;
    (*this).prompt.length = 0;
    memset((*this).prompt.input, 0, 8192);
    if (term_init(this)) {
        return (1);
    }
    (*this).builtin = shell_builtin_hash_create();
    (*this).alias = NULL;
    (*this).bindkey = shell_bindkey_hash_create();
    return (!((*this).builtin && (*this).bindkey));
}
