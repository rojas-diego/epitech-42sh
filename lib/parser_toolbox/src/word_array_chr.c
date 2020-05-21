/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** word_array_chr
*/

#include <string.h>
#include <stdlib.h>

#include "parser_toolbox/word_array_chr.h"

/* new[i] = temp ? strdup(temp) : strdup(word_array[i]); */
char **ptb_word_array_parse(
    char **word_array,
    size_t size,
    char c,
    char *(*func)(const char *, int)
)
{
    char **new = malloc(sizeof(char *) * (size + 1));
    char *temp = NULL;

    if (!new) {
        return (NULL);
    }
    new[size] = NULL;
    for (size_t i = 0; i < size; ++i) {
        temp = func(word_array[i], c);
        new[i] = temp ? temp + 1 : word_array[i];
    }
    return (new);
}

char **ptb_word_array_chr(char **word_array, size_t size, char c)
{
    return (ptb_word_array_parse(word_array, size, c, strchr));
}

char **ptb_word_array_rchr(char **word_array, size_t size, char c)
{
    return (ptb_word_array_parse(word_array, size, c, strrchr));
}
