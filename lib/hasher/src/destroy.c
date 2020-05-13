/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_destroy
*/

#include <stdlib.h>

/* */
#include "hasher/destroy.h"

void hasher_destroy(
    struct hasher *hasher,
    _Bool destroy_key,
    _Bool destroy_data
)
{
    for (struct hasher *keep = hasher; hasher; keep = hasher) {
        if (destroy_key) {
            free(hasher->key);
        }
        if (destroy_data) {
            free(hasher->data);
        }
        hasher = hasher->next;
        free(keep);
    }
}
