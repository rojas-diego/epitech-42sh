/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** apply
*/

#include <stddef.h>

#include "dnode/apply.h"
#include "dnode/goto.h"

void dnode_apply(struct dnode_s *list, void (*func)(void *))
{
    struct dnode_s *curr = NULL;

    if (!func) {
        return;
    }
    curr = dnode_goto_start(list);
    for (; curr; curr = curr->next) {
        func(curr->data);
    }
}
