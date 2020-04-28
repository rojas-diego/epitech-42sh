/*
** EPITECH PROJECT, 2019
** mynode
** File description:
** node_free
*/

#include <stdlib.h>

#include "mynode.h"

/*
** @DESCRIPTION
**   Frees an entire list of nodes.
** @RETURN_VALUE
**   None.
*/
void node_free(NODE **head, void (*function)(void *))
{
    NODE *current = *head;
    NODE *temp;

    while (current != NULL) {
        temp = current;
        if (function)
            function(temp->data);
        current = current->next;
        free(temp);
    }
    *head = NULL;
}
