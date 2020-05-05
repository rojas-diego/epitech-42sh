/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** ptb_argv_length
*/

/* */
#include "parser_toolbox/argv_length.h"

size_t ptb_argv_length(const char * const *argv)
{
    size_t len = 0;

    while (argv[len]) {
        ++len;
    }
    return (len);
}
