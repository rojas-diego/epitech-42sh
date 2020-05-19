/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** find
*/

#include <stddef.h>

#include "dnode/find.h"

struct dnode_s *dnode_find_before(struct dnode_s *list, _Bool (*func)(void *))
{
    for (struct dnode_s *curr = list; curr; curr = curr->prev) {
        if (func(curr->data)) {
            return (curr);
        }
    }
    return (NULL);
}

struct dnode_s *dnode_find_after(struct dnode_s *list, _Bool (*func)(void *))
{
    for (struct dnode_s *curr = list; curr; curr = curr->next) {
        if (func(curr->data)) {
            return (curr);
        }
    }
    return (NULL);
}

struct dnode_s *dnode_find(struct dnode_s *list, _Bool (*func)(void *))
{
    struct dnode_s *node = dnode_find_before(list, func);

    if (!node) {
        node = dnode_find_after(list, func);
    }
    return (node);
}
