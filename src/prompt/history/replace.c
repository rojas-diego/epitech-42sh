/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** replace
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include "parser_toolbox/consts.h"
#include "parser_toolbox/cmp_string.h"
#include "parser_toolbox/sub_string.h"
#include "proto/prompt/history.h"

static size_t word_len(const char *str)
{
    size_t i = 0;

    for (; str[i] && (!strchr(PTB_WHITESPACES, str[i])
        || str[i] != '!'); ++i) {}
    return (i);
}

static _Bool history_can_replace(struct history_s *history, char **str, int i)
{
    struct dnode_s *node = NULL;
    size_t len = 0;
    char *substring = NULL;

    if ((*str)[i] == '!' && (!i || strchr(PTB_WHITESPACES, (*str)[i - 1]))) {
        substring = ptb_sub_string(*str, i + 1, i + word_len(&(*str)[i + 1]));
        if (!substring) {
            return (0);
        }
        len = strlen(substring) + 1 + i;
        node = dnode_find_after(history->list, substring, &ptb_ncmp_string);
        if (!node) {
            dprintf(2, "!%s: Event not found.\n", substring ? substring : "");
            return (1);
        }
        (*str)[i] = 0;
        asprintf(str, "%s%s%s", *str, (char *) node->data, &(*str)[len]);
    }
    return (0);
}

/*
** @Description
**    this function replace all '!' by the matching previous command
*/
_Bool history_replace(struct history_s *history, char **str)
{
    for (size_t i = 0; (*str)[i]; ++i) {
        if (history_can_replace(history, str, i)) {
            return (1);
        }
    }
    return (0);
}
