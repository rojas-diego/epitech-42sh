/*
** EPITECH PROJECT, 2020
** hasher
** File description:
** hasher_get_data
*/

#include <string.h>

#include "hasher/get.h"
/* */
#include "hasher/get_data.h"

void *hasher_get_data(struct hasher_s *hasher, const char *key)
{
    struct hasher_s *match = hasher_get(hasher, key);

    return (match ? match->data : NULL);
}
