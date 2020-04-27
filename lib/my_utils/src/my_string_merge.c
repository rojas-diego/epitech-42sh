/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** my_string_merge
*/

#include "my_utils/my_strlen.h"
#include "my_utils/my_strcpy.h"
#include "my_utils/my_strcat.h"
#include "my_utils/my_string_merge.h"

char *my_string_merge(char *str1, char *str2)
{
    char *new = malloc(sizeof(char) * (unsigned long)(my_strlen(str1)
        + my_strlen(str2) + 1));

    my_strcpy(new, str1);
    my_strcat(new, str2);
    return (new);
}
