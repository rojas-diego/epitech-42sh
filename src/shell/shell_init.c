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
#include "proto/shell/local_variables.h"
#include "proto/prompt/history.h"

/* TODO: parse av: if fd replace STDIN_FILENO in isatty by fildes */

/*
** @DESCRIPTION
**   Initialises a local `struct sh` and inits all of its members.
*/
int shell_struct_initialise(
    struct sh *this,
    __attribute__((unused)) int ac,
    char *const *av,
    char *const *ep
)
{
    int fd = STDIN_FILENO;

    *this = (struct sh) {
        .debug_mode = check_debug_mode(av), .active = true, .rawinput = NULL,
        .tokens = NULL, .pgid = 0, .envp = ep, .prompt = {{0}},
        .atty = isatty(fd), .history = {0},
        .builtin = shell_builtin_hash_create(), .alias = NULL,
        .bindkey = NULL,
        .local_var = local_variables_init(), .error = ER_NONE, .job = NULL,
        .fd = fd, .expression = NULL, .debug = {.depth = 0}
    };
    if (term_init(this)) {
        return (1);
    }
    history_init(&this->history);
    this->bindkey = shell_bindkey_hash_create();
    return (
        !this->builtin || (this->atty && !this->bindkey)
    );
}
