/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** parse
*/

#include <stdio.h>
#include <unistd.h>

#include "parser_toolbox/string_split.h"
#include "parser_toolbox/consts.h"
#include "parser_toolbox/unquote.h"

#include "proto/exec/magic/parse.h"

int do_merge(process_s *proc, char **to_merge, size_t index)
{
    return (0);
}

char **do_magic_parse(struct expr_wordlist_s *words)
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
    fclose(stream);
    close(fd);
    return (ptb_string_split(buffer, PTB_WHITESPACES));
}
