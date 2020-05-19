/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** ptb_remove_char
*/

#include <stdlib.h>
#include <string.h>

#include "parser_toolbox/sub_string.h"

char *ptb_sub_string(const char *str, size_t start, size_t end)
{
    size_t len = end - start + 1;
    char *substr = NULL;

    if (start > end) {
        return (NULL);
    }
    substr = malloc(sizeof(char) * (len + 1));
    if (substr == NULL) {
        return (NULL);
    }
    memcpy((void *) substr, (void *) str + start, len);
    substr[len] = '\0';
    return (substr);
}
