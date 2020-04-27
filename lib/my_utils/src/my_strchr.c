/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** my_get_last_occ
*/

#include <stddef.h>

#include "my_utils/my_strchr.h"

char *my_strchr(char *s, char c)
{
    while (*s != '\0') {
        if (*s == c) {
            return (s);
        }
        ++s;
    }
    return (NULL);
}
