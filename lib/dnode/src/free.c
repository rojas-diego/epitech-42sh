/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** free
*/

/* free */
#include <stdlib.h>

#include "dnode/free.h"

void dnode_free(struct dnode_s **head, void (*func)(void *))
{
    struct dnode_s *prev = NULL;

    if (!*head) {
        return;
    }
    for (; (*head)->prev; *head = (*head)->prev) {}
    for (struct dnode_s *curr = *head; curr; curr = curr->next) {
        if (prev) {
            free(prev);
        }
        if (func) {
            func(curr->data);
        }
        prev = curr;
    }
    *head = NULL;
}
