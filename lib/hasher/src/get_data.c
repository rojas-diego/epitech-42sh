/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_get_data
*/

#include <string.h>

/* */
#include "hasher/get_data.h"

void *hasher_get_data(struct hasher *hasher, const char *key)
{
    for (; hasher != NULL; hasher = hasher->next) {
        if (!strcmp(hasher->key, key)) {
            return (hasher->data);
        }
    }
    return (NULL);
}
