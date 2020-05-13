/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** history
*/

#include <string.h>

#include "hasher/insert_data.h"

#include "proto/shell/history.h"

struct hasher *shell_history_hash_create(void)
{
    struct hasher *hash = NULL;
    void *data = NULL;

    for (int i = 0; i < ALIAS_COUNT; ++i) {
        data = (void *) strdup(ALIAS_DICT[i].data);
        if (data == NULL) {
            return (NULL);
        }
        if (hasher_insert_data(
            &hash,
            strdup(ALIAS_DICT[i].key),
            data
        )) {
            return (NULL);
        }
    }
    return (hash);
}
