/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_get
*/

#include <string.h>

/* */
#include "hasher/get.h"

struct hasher *hasher_get(struct hasher *hasher, const char *key)
{
    for (; hasher != NULL; hasher = hasher->next) {
        if (!strcmp(hasher->key, key)) {
            return (hasher);
        }
    }
    return (NULL);
}
