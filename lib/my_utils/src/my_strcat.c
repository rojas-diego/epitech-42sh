/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** my_strcat
*/

#include "my_utils/my_strcat.h"
#include "my_utils/my_strncat.h"

char *my_strcat(char *dest, char const *src)
{
    int index = 0;

    while (dest[index] != '\0')
        index++;
    while (*src != '\0')
        dest[index++] = *src++;
    dest[index] = '\0';
    return (dest);
}

char *my_strncat(char *dest, char const *src, int n)
{
    int index = 0;

    while (dest[index] != '\0')
        index++;
    while (*src != '\0' && n-- > 0)
        dest[index++] = *src++;
    dest[index] = '\0';
    return (dest);
}
