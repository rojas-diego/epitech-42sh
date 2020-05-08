/*
** EPITECH PROJECT, 2020
** mynode
** File description:
** node_to_table
*/

#include <stdlib.h>

#include "mynode.h"

/*
** @DESCRIPTION
**   This function transforms a linked list into a NULL
**   terminated 2d array.
*/
void **node_to_table(NODE *const head)
{
    unsigned int i = 0;
    void **table = malloc(sizeof(void *) * (node_size(head) + 1));

    for (NODE *curr = head; curr; curr = curr->next) {
        table[i] = curr->data;
        i++;
    }
    table[i] = NULL;
    return table;
}

/*
** @DESCRIPTION
**   This function transforms a linked list into a NULL
**   terminated 2d array.
*/
void node_from_table(void **array, NODE **head)
{
    for (unsigned int i = 0; array[i]; i++) {
        node_insert(head, array[i]);
    }
    node_reverse(head);
}