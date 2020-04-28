/*
** EPITECH PROJECT, 2019
** lib/mynode
** File description:
** node_apply
*/

#include <stdlib.h>

#include "mynode.h"

void node_apply(NODE *head, fnode_t function)
{
    for (NODE *curr = head; curr; curr = curr->next) {
        function(curr->data);
    }
}