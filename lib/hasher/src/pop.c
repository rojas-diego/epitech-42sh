/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_pop
*/

#include <string.h>

/* */
#include "hasher/pop.h"

struct hasher *hasher_pop(struct hasher **hasher, const char *key)
{
    struct hasher *poped = NULL;
    struct hasher *current = *hasher;

    if (!strcmp(current->key, key)) {
        *hasher = current->next;
        current->next = NULL;
        return (current);
    }
    for (; current->next != NULL; current = current->next) {
        if (strcmp(current->next->key, key)) {
            continue;
        }
        poped = current->next;
        current->next = current->next->next;
        poped->next = NULL;
        break;
    }
    return (poped);
}
