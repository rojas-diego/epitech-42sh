/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_insert_data
*/

#include <stdlib.h>

#include "hasher/create.h"
#include "hasher/insert.h"
/* */
#include "hasher/insert_data.h"

enum hasher_e hasher_insert_data(
    struct hasher_s **hasher,
    char *key,
    void *data
)
{
    struct hasher_s *new = hasher_create(key, data);

    if (new == NULL) {
        return (HASHER_ALLOCATION_FAIL);
    }
    hasher_insert(hasher, new);
    return (HASHER_SUCCESS);
}

enum hasher_e hasher_insert_data_ordered(
    struct hasher_s **hasher,
    char *key,
    void *data
)
{
    struct hasher_s *new = hasher_create(key, data);

    if (new == NULL) {
        return (HASHER_ALLOCATION_FAIL);
    }
    hasher_insert_ordered(hasher, new);
    return (HASHER_SUCCESS);
}
