/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** find
*/

#include <stddef.h>

#include "dnode/find.h"

struct dnode_s *dnode_find_before(
    struct dnode_s *list,
    void *data,
    _Bool (*func)(void *, void *)
)
{
    for (struct dnode_s *curr = list; curr; curr = curr->prev) {
        if (func(data, curr->data)) {
            return (curr);
        }
    }
    return (NULL);
}

struct dnode_s *dnode_find_after(
    struct dnode_s *list,
    void *data,
    _Bool (*func)(void *, void *)
)
{
    for (struct dnode_s *curr = list; curr; curr = curr->next) {
        if (func(data, curr->data)) {
            return (curr);
        }
    }
    return (NULL);
}

struct dnode_s *dnode_find(
    struct dnode_s *list,
    void *data,
    _Bool (*func)(void *, void *)
)
{
    struct dnode_s *node = dnode_find_before(list, data, func);

    if (!node) {
        node = dnode_find_after(list, data, func);
    }
    return (node);
}
