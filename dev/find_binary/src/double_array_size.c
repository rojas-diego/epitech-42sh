/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** double_array_size
*/

#include <stdlib.h>

/* */
#include "double_array_size.h"

int double_array_size(void **array, size_t *allocated)
{
    if (*array != NULL) {
        free(*array);
    }
    *allocated *= 2;
    *array = malloc(sizeof(char) * (*allocated));
    return (*array == NULL);
}
