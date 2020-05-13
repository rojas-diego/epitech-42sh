/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** destroy
*/

#include "hasher/destroy.h"

#include "types/shell.h"
#include "proto/shell.h"

/* hasher_destroy(shell->binkey, false, false); */

/*
** @DESCRIPTION
**   Free shell
*/
void shell_destroy(struct sh *shell)
{
    hasher_destroy(shell->builtin, true, false);
    hasher_destroy(shell->alias, true, true);
}
