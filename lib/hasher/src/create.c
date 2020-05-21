/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_create
*/

#include <stdlib.h>

/* */
#include "hasher/create.h"

struct hasher_s *hasher_create(char *key, void *data)
{
    struct hasher_s *hasher = NULL;

    if (key == NULL) {
        return (NULL);
    }
    hasher = (struct hasher_s *) malloc(sizeof(struct hasher_s));
    if (hasher == NULL) {
        return (NULL);
    }
    hasher->key = key;
    hasher->data = data;
    hasher->next = NULL;
    return (hasher);
}
