/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** my_strcmp
*/

#include "my_utils/my_strcmp.h"

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
