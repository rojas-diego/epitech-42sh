/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** append
*/

#include <stddef.h>

#include "dnode/append.h"
#include "dnode/create.h"

/*
** @Description:
**    Add a node at the end of the list
*/
void dnode_append(struct dnode_s **head, struct dnode_s *node)
{
    struct dnode_s *current = *head;

    if (!current) {
        *head = node;
        return;
    }
    for (; current->next; current = current->next) {}
    node->prev = current;
    current->next = node;
    node->next = NULL;
}

/*
** @Description:
**    Create a node and add it at the end of the list
*/
void dnode_append_data(struct dnode_s **head, void *data)
{
    struct dnode_s *new = dnode_create(data);

    if (!new) {
        return;
    }
    dnode_append(head, new);
}
