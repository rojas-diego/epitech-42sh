/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** ptb_remove_char
*/

#include <stdio.h>

#include "parser_toolbox/sort_string.h"
#include "parser_toolbox/longest_string.h"
#include "parser_toolbox/display_strings.h"
#include "parser_toolbox/display_strings_equalize.h"

void ptb_display_strings_equalize(
    char * const *strings,
    size_t length,
    size_t win_width
)
{
    size_t longest_string = ptb_longest_string(strings, length);

    if (longest_string > win_width) {
        ptb_display_strings(strings, length);
        return;
    }
    for (size_t i = 0; i < length; ++i) {
        for (size_t j = longest_string + 2; j < win_width && i < length; ++i) {
            j += longest_string + 2;
            printf("%*s", -((int) longest_string + 2), strings[i]);
        }
        puts("");
    }
}

void ptb_display_sorted_strings_equalize(
    char * const *strings,
    size_t length,
    size_t win_width
)
{
    ptb_sort_string(strings, length);
    ptb_display_strings_equalize(strings, length, win_width);
}
