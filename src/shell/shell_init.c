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
#include "proto/shell/check_debug_mode.h"
#include "proto/prompt/history.h"

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
    (*this).fd = STDIN_FILENO;
    (*this).atty = isatty((*this).fd);
    (*this).prompt.cursor = 0;
    (*this).prompt.length = 0;
    (*this).job = NULL;
    memset((*this).prompt.input, 0, 8192);
    history_init(&this->history);
    if (term_init(this)) {
        return (1);
    }
    (*this).builtin = shell_builtin_hash_create();
    (*this).bindkey = shell_bindkey_hash_create();
    (*this).alias = NULL;
    this->debug_mode = check_debug_mode(av);
    return (!(*this).builtin || ((*this).atty && !(*this).bindkey));
}
