/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** word_array_chr
*/

#ifndef PARSER_TOOLBOX_WORD_ARRAY_CHR_H_
#define PARSER_TOOLBOX_WORD_ARRAY_CHR_H_

#include <stddef.h>

char **ptb_word_array_parse(
    char **word_array,
    size_t size,
    char c,
    char *(*func)(const char *, int)
);

char **ptb_word_array_chr(char **word_array, size_t size, char c);

char **ptb_word_array_rchr(char **word_array, size_t size, char c);

#endif /* !PARSER_TOOLBOX_WORD_ARRAY_CHR_H_ */
