/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** history
*/

/* printf */
#include <stdio.h>

#include "dnode/type.h"
#include "types/shell.h"
#include "types/history.h"

int builtin_history_handler(
    struct sh *shell,
    const char * const *argv
)
{
    (void)argv;
    for (struct dnode_s *curr = shell->history.list; curr; curr = curr->next) {
        printf("%s\n", (char *) curr->data);
    }
    return (0);
}
