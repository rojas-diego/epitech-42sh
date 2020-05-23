/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** insert
*/

#include <string.h>
#include <stdlib.h>

#include "dnode.h"
#include "proto/prompt/history.h"
#include "types/history.h"
#include "parser_toolbox/consts.h"

const size_t HISTORY_MAX_SIZE = 10;

static _Bool history_can_insert(struct dnode_s *list, char const *line)
{
    if (!list) {
        return (1);
    }
    if (!strcmp((char *) list->data, line)) {
        return (0);
    }
    for (size_t i = 0; line[i]; ++i) {
        if (!strchr(PTB_WHITESPACES, line[i])) {
            return (1);
        }
    }
    return (0);
}

void history_insert(struct history_s *history, char const *line)
{
    struct dnode_s *last = NULL;
    size_t len = strlen(line);
    char *new = strdup(line);

    if (!new || !history_can_insert(history->list, line)) {
        history->curr = NULL;
        return;
    }
    if (new[len - 1] == '\n') {
        new[len - 1] = 0;
    }
    dnode_insert_data(&(history->list), new);
    history->curr = NULL;
    ++history->size;
    if (history->size > HISTORY_MAX_SIZE) {
        --history->size;
        last = dnode_goto_end(history->list);
        last->prev->next = NULL;
        free(last->data);
        free(last);
    }
}
