/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** my_memcpy
*/

#include "my_utils/my_memcpy.h"

void my_memcpy(void *new, const void *prev, size_t size)
{
    char *dest = (char *) new;
    const char *source = (const char *) prev;

    if (dest != NULL && source != NULL) {
        while (size--) {
            *(dest++) = *(source++);
        }
    }
}
