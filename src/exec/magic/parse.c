/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** parse
*/

#include <stdio.h>
#include "proto/exec/magic/parse.h"
#include "parser_toolbox/string_split.h"
#include "parser_toolbox/consts.h"

char **do_magic_parse(int fd)
{
    FILE *stream = fdopen(fd, "r");
    char *buffer = NULL;
    size_t n = 0;

    if (!stream) {
        return (NULL);
    }
    if (getdelim(&buffer, &n, 0, stream) < 0) {
        return (NULL);
    }
    return (ptb_string_split(buffer, PTB_WHITESPACES));
}
