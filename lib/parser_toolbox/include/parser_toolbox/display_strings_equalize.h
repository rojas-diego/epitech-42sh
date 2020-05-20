/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** parser_toolbox display_strings_equalize
*/

#ifndef PARSER_TOOLBOX_DISPLAY_STRING_EQUALIZE_H_
#define PARSER_TOOLBOX_DISPLAY_STRING_EQUALIZE_H_

#include <stddef.h>

void ptb_display_strings_equalize(
    char * const *strings,
    size_t length,
    size_t win_width
);

void ptb_display_sorted_strings_equalize(
    char * const *strings,
    size_t length,
    size_t win_width
);

#endif /* !PARSER_TOOLBOX_DISPLAY_STRING_EQUALIZE_H_ */
