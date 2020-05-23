/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_insert
*/

#include <string.h>

/* */
#include "hasher/override.h"

struct hasher_s *hasher_override(struct hasher_s **hasher, struct hasher_s *to_insert)
{
    struct hasher_s *overrided = NULL;

    if (!(*hasher))
        return (NULL);
    if (!(strcmp(to_insert->key, (*hasher)->key))) {
        to_insert->next = (*hasher)->next;
        overrided = *hasher;
        *hasher = to_insert;
        return (overrided);
    }
    for (struct hasher_s *hash = *hasher; hash->next; hash = hash->next) {
        if (!(strcmp(to_insert->key, hash->next->key))) {
            overrided = hash->next;
            hash->next = to_insert;
            to_insert->next = overrided->next;
            overrided->next = NULL;
            break;
        }
    }
    return (overrided);
}
