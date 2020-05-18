/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_filter
*/

#include <string.h>

/* */
#include "hasher/filter.h"

struct hasher *hasher_filter(
    struct hasher **hasher,
    const char *key,
    size_t len
)
{
    struct hasher *filtered = NULL;
    struct hasher *holder = NULL;
    struct hasher *current = *hasher;

    if (!current)
        return (NULL);
    if (strncmp(current->key, key, len)) {
        filtered = current;
        *hasher = current->next;
        filtered->next = NULL;
    }
    for (; current->next != NULL; current = current->next) {
        if (strncmp(current->next->key, key, len))
            continue;
        holder = current->next;
        current->next = current->next->next;
        holder->next = filtered;
        filtered = holder;
    }
    return (filtered);
}
