/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** destroy
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "proto/prompt/history.h"

void history_destroy(struct history_s *history)
{
    int fd = open(".42sh_history", O_WRONLY | O_TRUNC | O_CREAT, 0666);

    if (fd == -1) {
        return;
    }
    for (struct dnode_s *curr = dnode_goto_end(history->list);
        curr; curr = curr->prev) {
        write(fd, curr->data, strlen(curr->data));
        write(fd, "\n", 1);
    }
    close(fd);
    dnode_free(&history->list, &free);
}
