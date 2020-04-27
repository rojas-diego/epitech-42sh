/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_reallocate
*/

#ifndef REALLOCATE_H_
#define REALLOCATE_H_

#include <stdlib.h>

#define DOUBLE_ARRAY(prev, type, old_count, count) ((type *) \
    my_reallocate(prev, sizeof(type) * (old_count), sizeof(type) * (count)))

void *my_reallocate(void *previous, size_t old_size, size_t new_size);

#endif /* !REALLOCATE_H_ */
