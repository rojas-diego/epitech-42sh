/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_insert
*/

#include <string.h>

/* */
#include "hasher/override.h"

struct hasher *hasher_override(struct hasher **hasher, struct hasher *to_insert)
{
    struct hasher *overrided = NULL;

    if (!(*hasher))
        return (NULL);
    if (!(strcmp(to_insert->key, (*hasher)->key))) {
        to_insert->next = (*hasher)->next;
        overrided = *hasher;
        *hasher = to_insert;
        return (overrided);
    }
    for (struct hasher *hash = *hasher; hash->next; hash = hash->next) {
        if (!(strcmp(to_insert->key, hash->next->key))) {
            overrided = hash->next;
            hash->next = to_insert;
            to_insert->next = overrided;
            overrided->next = NULL;
            break;
        }
    }
    return (overrided);
}
