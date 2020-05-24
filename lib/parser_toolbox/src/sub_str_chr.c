/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** sub_str_chr
*/

#include "parser_toolbox/sub_str_chr.h"

bool ptb_sub_str_chr(
    char *str,
    size_t start,
    size_t end,
    char c
)
{
    if (start > end) {
        return (false);
    }
    for (size_t i = start; i < end; ++i) {
        if (str[i] == c) {
            return (true);
        }
    }
    return (false);
}
