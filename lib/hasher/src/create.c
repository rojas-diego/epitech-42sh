/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_create
*/

#include <stdlib.h>

/* */
#include "hasher/create.h"

struct hasher *hasher_create(char *key, void *data)
{
    struct hasher *hasher = NULL;

    if (key == NULL) {
        return (NULL);
    }
    hasher = (struct hasher *) malloc(sizeof(struct hasher));
    if (hasher == NULL) {
        return (NULL);
    }
    hasher->key = key;
    hasher->data = data;
    return (hasher);
}
