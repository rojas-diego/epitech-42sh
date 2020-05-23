/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** destroy
*/

#include <unistd.h>

#include "hasher/destroy.h"

#include "types/shell.h"
#include "proto/shell.h"
#include "proto/prompt/history.h"
#include "proto/shell/local_variables.h"

/* hasher_destroy(shell->binkey, false, false); */

/*
** @DESCRIPTION
**   Free shell
*/
void shell_destroy(struct sh *shell)
{
    if (shell->fd != STDIN_FILENO) {
        close(shell->fd);
    }
    hasher_destroy(shell->builtin, true, false);
    hasher_destroy(shell->alias, true, true);
    hasher_destroy(shell->bindkey, true, false);
    history_destroy(&shell->history);
    local_variables_destroy(shell->local_var);
}
