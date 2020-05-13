/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_replace_key
*/

#include <stddef.h>

#include "hasher/get.h"
/* */
#include "hasher/replace_key.h"

char *hasher_replace_key(
    struct hasher *hasher,
    const char *current_key,
    char *new_key
)
{
    struct hasher *match = hasher_get(hasher, current_key);
    char *old_key = NULL;

    if (match) {
        old_key = match->key;
        match->key = new_key;
    }
    return (old_key);
}
