/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** history
*/

/* printf */
#include <stdio.h>

#include "dnode/type.h"
#include "dnode/goto.h"
#include "types/shell.h"
#include "types/history.h"

int builtin_history_handler(
    struct sh *shell,
    const char * const *argv
)
{
    size_t i = 0;

    (void)argv;
    for (struct dnode_s *curr = dnode_goto_end(shell->history.list);
        curr; curr = curr->prev) {
        printf("%5lu\t%s\n", i, (char *) curr->data);
        ++i;
    }
    return (0);
}
