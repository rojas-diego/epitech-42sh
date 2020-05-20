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

const size_t HISTORY_MAX_SIZE = 100;

void history_insert(struct history_s *history, char const *line)
{
    struct dnode_s *last = NULL;

    dnode_insert_data(&(history->list), strdup(line));
    history->curr = NULL;
    ++history->size;
    if (history->size == HISTORY_MAX_SIZE) {
        last = dnode_goto_end(history->list);
        last->prev->next = NULL;
        free(last->data);
        free(last);
    }
}
