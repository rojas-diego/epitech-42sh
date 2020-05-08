/*
** EPITECH PROJECT, 2020
** find_binary
** File description:
** extend_path
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

/* */
#include "extend_path.h"

char *extend_path(const char *path, const char *extend)
{
    size_t path_len = strlen(path);
    size_t extend_len = strlen(extend);
    bool no_slash = path[path_len - 1] != '/';
    char *new_path = (char *) malloc(
        sizeof(char) * (path_len + extend_len + 1 + no_slash)
    );

    if (new_path == NULL) {
        perror("malloc");
        return (NULL);
    }
    memcpy(new_path, path, path_len);
    if (no_slash) {
        new_path[path_len] = '/';
    }
    memcpy(&(new_path[path_len + no_slash]), extend, extend_len + 1);
    return (new_path);
}
