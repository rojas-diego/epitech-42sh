/*
** EPITECH PROJECT, 2019
** my_utils
** File description:
** my_strdup
*/

#include "my_utils/my_strdup.h"

char *my_strdup(const char *str)
{
    char *temp;
    char *new_str;
    unsigned long len = 0;

    while (str[len])
        len++;
    new_str = malloc(sizeof(char) * (len + 1));
    temp = new_str;
    while (*str != '\0')
        *temp++ = *str++;
    *temp = '\0';
    return (new_str);
}
