/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** error_reporter
*/

#include <stdlib.h>
#include <string.h>

#include "mynode.h"

typedef enum errstore_mode_e {
    errorFetch,
    errorAdd,
    errorEmpty
} errstore_mode_t;

typedef struct error_s {
    int code;
    char *message;
} error_t;

/*
** @DESCRIPTION
**   This function stores errors from the shell's parser.
*/
void *error_store(enum errstore_mode_e mode, const struct error_s error)
{
    static node_t *store = 0;
    struct error_s *new;

    if (mode == errorEmpty) {
        node_free(store, free);
        return 0;
    } if (mode == errorFetch) {
        return store;
    } else {
        new = malloc(sizeof(struct error_s));
        memcpy(new, &error, sizeof(struct error_s));
        node_insert(&store, new);
    }
}