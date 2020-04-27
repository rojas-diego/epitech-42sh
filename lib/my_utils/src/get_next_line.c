/*
** EPITECH PROJECT, 2020
** my_utils
** File description:
** get_next_line
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "get_next_line.h"

static char *my_strchr(char *str, char c)
{
    while (*str != c && *str != '\0')
        str++;
    return (*str != '\0' ? str : NULL);
}

static int make_line_bigger(char **line, char *buffer, unsigned long size)
{
    char *tmp = *line;
    int i = 0;

    if (*line == NULL) {
        *line = malloc(sizeof(char) * (size + 1));
        if (*line == NULL)
            return (1);
        for (i = -1; buffer[++i] != '\0'; (*line)[i] = buffer[i]);
    } else {
        while (tmp[i++] != '\0');
        *line = malloc(sizeof(char) * ((unsigned long)i + size));
        if (*line == NULL)
            return (1);
        for (i = -1; tmp[++i] != '\0'; (*line)[i] = tmp[i]);
        free(tmp);
        for (int j = 0; buffer[j] != '\0'; i++, j++)
            (*line)[i] = buffer[j];
    }
    (*line)[i] = '\0';
    return (0);
}

static int put_rest_buffer_in_line(char *buffer, char **line, char *ptr)
{
    unsigned long i = 0;

    if (ptr != NULL) {
        *ptr++ = '\0';
        while (buffer[i] != '\0')
            i++;
        make_line_bigger(line, buffer, i);
        for (i = 0; ptr[i] != '\0'; i++)
            buffer[i] = ptr[i];
    } else {
        make_line_bigger(line, buffer, READ_SIZE);
    }
    for (; i < READ_SIZE; i++)
        buffer[i] = '\0';
    return (0);
}

static char *gnl_get_return_value(char *line, ssize_t nb_read)
{
    if (line != NULL && *line == '\0' && nb_read < 1) {
        free(line);
        return (NULL);
    }
    return (line);
}

char *get_next_line(int fd)
{
    static char buffer[READ_SIZE + 1] = {'\0'};
    char *line = NULL;
    char *ptr = my_strchr(buffer, '\n');
    ssize_t nb_read = fd != -1;

    if (*buffer != '\0'
        && (put_rest_buffer_in_line(buffer, &line, ptr) || ptr != NULL))
        return (line);
    while (nb_read > 0 && ptr == NULL) {
        nb_read = read(fd, buffer, READ_SIZE);
        buffer[nb_read == -1 ? 0 : nb_read] = '\0';
        ptr = my_strchr(buffer, '\n');
        if (ptr == NULL && nb_read >= 0
            && make_line_bigger(&line, buffer, (unsigned long)nb_read) == 1)
            return (NULL);
    }
    if (ptr != NULL)
        put_rest_buffer_in_line(buffer, &line, ptr);
    return (gnl_get_return_value(line, nb_read));
}
