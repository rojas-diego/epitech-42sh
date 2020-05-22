/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_get
*/

#include <string.h>

/* */
#include "hasher/get.h"

struct hasher_s *hasher_get(struct hasher_s *hasher, const char *key)
{
    if (key == NULL) {
        return (NULL);
    }
    for (; hasher != NULL; hasher = hasher->next) {
        if (!strcmp(hasher->key, key)) {
            return (hasher);
        }
    }
    return (NULL);
}
