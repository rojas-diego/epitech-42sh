/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** my_strcpy
*/

#include "my_utils/my_strcpy.h"

char *my_strcpy(char *dest, char const *src)
{
    while (*src != '\0')
        *dest++ = *src++;
    *dest = '\0';
    return (dest);
}
