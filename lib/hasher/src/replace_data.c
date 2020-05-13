/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_replace_data
*/

#include <stddef.h>

#include "hasher/get.h"
/* */
#include "hasher/replace_data.h"

void *hasher_replace_data(
    struct hasher *hasher,
    const char *current_data,
    char *new_data
)
{
    struct hasher *match = hasher_get(hasher, current_data);
    void *old_data = NULL;

    if (match) {
        old_data = match->data;
        match->data = new_data;
    }
    return (old_data);
}
