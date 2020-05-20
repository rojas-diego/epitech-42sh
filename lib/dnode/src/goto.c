/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** goto
*/

#include <stddef.h>

#include "dnode/goto.h"

struct dnode_s *dnode_goto_end(struct dnode_s *list)
{
    struct dnode_s *curr = list;

    if (!curr) {
        return (NULL);
    }
    for (; curr->next; curr = curr->next) {}
    return (curr);
}

struct dnode_s *dnode_goto_start(struct dnode_s *list)
{
    struct dnode_s *curr = list;

    if (!curr) {
        return (NULL);
    }
    for (; curr->prev; curr = curr->prev) {}
    return (curr);
}
