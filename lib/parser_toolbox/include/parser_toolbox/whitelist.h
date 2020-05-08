/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** parser_toolbox withelist
*/

#ifndef PARSER_TOOLBOX_WHITELIST_H_
#define PARSER_TOOLBOX_WHITELIST_H_

#include <stdbool.h>

bool ptb_whitelist(const char *string, const char * restrict withelist);

bool ptb_whitelist_digit(const char *string);

bool ptb_whitelist_alphanum(const char *string);

#endif /* !PARSER_TOOLBOX_WHITELIST_H_ */
