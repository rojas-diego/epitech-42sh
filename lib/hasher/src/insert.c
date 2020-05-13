/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_insert
*/

#include <string.h>

/* */
#include "hasher/insert.h"

void hasher_insert(struct hasher **hasher, struct hasher *to_insert)
{
    to_insert->next = *hasher;
    (*hasher) = to_insert;
}

void hasher_insert_ordered(struct hasher **hasher, struct hasher *to_insert)
{
    if (strcmp(to_insert->key, (*hasher)->key) < 0) {
        to_insert->next = *hasher;
        (*hasher) = to_insert;
        return;
    }
    for (struct hasher *hash = *hasher; hash->next; hash = hash->next) {
        if (strcmp(to_insert->key, hash->next->key) < 0) {
            to_insert->next = hash->next;
            hash->next = to_insert;
            return;
        }
    }
}
