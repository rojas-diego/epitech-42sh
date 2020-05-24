/*
** EPITECH PROJECT, 2020
** find_binary
** File description:
** find_file_in_path
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "extend_path.h"
#include "find_file_in_path.h"

char *find_file_in_path(const char *path, const char *bin)
{
    char *current_path = extend_path(path, bin);

    if (access(current_path, F_OK) == 0)
        return (current_path);
    free(current_path);
    return (NULL);
}
