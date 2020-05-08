/*
** EPITECH PROJECT, 2020
** mynode
** File description:
** node_remove
*/

#include <stdlib.h>

#include "mynode.h"

static void node_cut(NODE **head, NODE *previous, NODE *curr, fnode_t free_func)
{
    NODE *to_free = curr;

    if (!previous)
        *head = curr->next;
    else
        previous->next = curr->next;
    if (free_func)
        free_func(to_free->data);
    free(to_free);
}

/*
** @DESCRIPTION
**   This function filters the list by removing the nodes for which the
**   function returns false.
*/
void node_filter(NODE **head, bool (*filter)(), fnode_t free_func)
{
    NODE *previous = 0;
    NODE *to_free = 0;

    for (NODE *curr = *head; curr;) {
        if (!filter(curr->data)) {
            to_free = curr;
            curr = curr->next;
            node_cut(head, previous, to_free, free_func);
        } else {
            previous = curr;
            curr = curr->next;
        }
    }
}
