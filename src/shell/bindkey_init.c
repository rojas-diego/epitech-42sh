/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** bindkey
*/

#include <string.h>

#include <curses.h>
/* setupterm */
#include <term.h>

#include "hasher/insert_data.h"

#include "proto/shell/term_init.h"
#include "proto/shell/bindkey.h"

#include "types/builtins/bindkey.h"
#include "constants/prompt/private_bindkey_init.h"

struct hasher_s *shell_bindkey_hash_create(void)
{
    struct hasher_s *hash = NULL;
    char *key = NULL;

    for (int i = 0; i < BINDKEY_COUNT; ++i) {
        key = i > 2 ? strdup(BINDKEY_DICT[i].key)
            : tigetstr(BINDKEY_DICT[i].key);
        if ((i < 3 && key == (char *) -1) || key == NULL) {
            return (NULL);
        }
        if (i < 3)
            key = strdup(key);
        if (hasher_insert_data(
            &hash,
            key,
            (void *) &BINDKEY_DICT[i].data
        )) {
            return (NULL);
        }
    }
    return (hash);
}
