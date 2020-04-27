/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** my_putstr
*/

#include "my_utils/my_strlen.h"
#include "my_utils/my_putstr.h"
#include "my_utils/my_putstr_fd.h"

int my_putstr(char const *str)
{
    int length = my_strlen(str);

    write(1, str, (size_t)length);
    return (0);
}

int my_putstr_fd(char const *str, int fd)
{
    int length = my_strlen(str);

    write(fd, str, (size_t)length);
    return (0);
}
