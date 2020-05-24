/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** str_join
*/

#include <string.h>
#include <stdlib.h>

#include "parser_toolbox/str_join.h"

char *ptb_str_join(const char *const *word_array, char const *str)
{
    char *new = NULL;
    size_t nb_words = 0;
    size_t len = 0;

    if (!word_array)
        return (NULL);
    for (; word_array[nb_words]; nb_words++)
        len += strlen(word_array[nb_words]);
    len += (str ? strlen(str) : 0) * (nb_words - 1);
    new = malloc(sizeof(char) * (len + 1));
    len = 0;
    for (size_t i = 0; word_array[i]; i++) {
        for (size_t j = 0; word_array[i][j]; j++, len++)
            new[len] = word_array[i][j];
        for (size_t j = 0; str && str[j] && word_array[i + 1]; j++, len++)
            new[len] = str[j];
    }
    return (new);
}
