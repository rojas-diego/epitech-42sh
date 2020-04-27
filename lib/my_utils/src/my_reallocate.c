/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** my_reallocate
*/

#include "my_utils/my_memcpy.h"
#include "my_utils/my_reallocate.h"

void *my_reallocate(void *previous, size_t old_size, size_t new_size)
{
    void *new = NULL;

    if (previous == NULL) {
        return (malloc(new_size));
    }
    if (new_size == 0) {
        free(previous);
        return (NULL);
    }
    if (old_size < new_size) {
        new = malloc(new_size);
        my_memcpy(new, previous, old_size);
    } else {
        new = previous;
    }
    return (new);
}
