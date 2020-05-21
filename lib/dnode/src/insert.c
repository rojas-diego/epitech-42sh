/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** insert
*/

#include <stddef.h>

#include "dnode/insert.h"
#include "dnode/create.h"

/*
** @Description:
**   Add a node at the beggining of the list
*/
void dnode_insert(struct dnode_s **head, struct dnode_s *node)
{
    node->next = *head;
    node->prev = NULL;
    if (*head) {
        (*head)->prev = node;
    }
    *head = node;
}

/*
** @Description:
**   Create a node and add it at the beggining of the list
*/
void dnode_insert_data(struct dnode_s **head, void *data)
{
    struct dnode_s *new = dnode_create(data);

    if (!new) {
        return;
    }
    dnode_insert(head, new);
}
