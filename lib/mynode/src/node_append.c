/*
** EPITECH PROJECT, 2020
** mynode
** File description:
** node_append
*/

#include <stdlib.h>

#include "mynode.h"

/*
** @DESCRIPTION
**   Append a node to the end of a linked list.
*/
void node_append(NODE **head, void *data)
{
    NODE *new = malloc(sizeof(*new));
    NODE *previous = NULL;

    if (!new || !data)
        return;
    new->data = data;
    new->next = NULL;
    for (NODE *curr = *head; curr; curr = curr->next)
        previous = curr;
    if (!previous)
        *head = new;
    else
        previous->next = new;
}
