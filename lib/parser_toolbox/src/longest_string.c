/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** ptb_longest_string
*/

#include <string.h>

#include "parser_toolbox/longest_string.h"

size_t ptb_longest_string(char * const *strings, size_t length)
{
    size_t longest_string = 0;
    size_t current;

    for (size_t i = 0; i < length; ++i) {
        current = strlen(strings[i]);
        if (current > longest_string) {
            longest_string = current;
        }
    }
    return (longest_string);
}
