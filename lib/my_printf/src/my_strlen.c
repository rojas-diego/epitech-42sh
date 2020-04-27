/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** str_len
*/

#include <wchar.h>

int my_strlen(char const *str)
{
    char const *tmp = str;

    while (*tmp)
        tmp++;
    return (tmp - str);
}

int my_strlen_wchar(wchar_t const *str)
{
    wchar_t const *tmp = str;

    while (*tmp)
        tmp++;
    return (tmp - str);
}

int my_non_printable_strlen(char const *str)
{
    int index = 0;

    while (*str != '\0') {
        if (*str > 31 && *str < 127)
            index++;
        else
            index+= 4;
        str++;
    }
    return (index);
}

int my_non_printable_strlen_wchar(wchar_t const *str)
{
    int index = 0;

    while (*str != '\0') {
        if (*str > 31 && *str < 127)
            index++;
        else
            index+= 4;
        str++;
    }
    return (index);
}
