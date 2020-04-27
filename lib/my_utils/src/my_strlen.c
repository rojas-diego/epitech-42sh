/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** my_strlen
*/

#include "my_utils/my_strlen.h"

int my_strlen(char const *str)
{
    char const *tmp = str;

    while (*tmp)
        tmp++;
    return (tmp - str);
}
