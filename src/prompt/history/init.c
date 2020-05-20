/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** init
*/

#include <stdio.h>
#include <string.h>

#include "proto/prompt/history.h"

static void history_create_from_file(
    struct history_s *history,
    char const *filepath
)
{
    FILE *stream = fopen(filepath, "r");
    char *buffer = NULL;
    size_t n = 0;
    ssize_t nbytes = 0;

    if (!stream) {
        return;
    }
    while (getline(&buffer, &n, stream) > 0) {
        for (; buffer[nbytes] && buffer[nbytes] != '\n'; ++nbytes) {}
        buffer[nbytes] = 0;
        history_insert(history, strdup(buffer));
    }
}

_Bool history_init(struct history_s *history)
{
    history->list = NULL;
    history->curr = NULL;
    history->size = 0;
    history_create_from_file(history, ".42sh_history");
    return (0);
}
