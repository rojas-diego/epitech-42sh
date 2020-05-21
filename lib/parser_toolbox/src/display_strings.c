/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** ptb_display_strings
*/

#include <stdio.h>

#include "parser_toolbox/sort_string.h"
#include "parser_toolbox/display_strings.h"

void ptb_display_strings(char * const *strings, size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        puts(strings[i]);
    }
}

void ptb_display_sorted_strings(char * const *strings, size_t length)
{
    ptb_sort_string(strings, length);
    ptb_display_strings(strings, length);
}
