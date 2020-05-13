/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** alias
*/

#include <string.h>

#include "hasher/insert_data.h"

#include "proto/shell/alias.h"

static const int BINDKEY_COUNT = 15;

static const struct {
    const char *key;
    const char *data;
} BINDKEY_DICT[] = {
    {"kdch1", &prompt_action_delete},
    {"khome", &prompt_action_home},
    {"kend", &prompt_action_end},
    {"\x1b[D", &prompt_action_left},
    {"\x1b[C", &prompt_action_right},
    {"\x1b[A", &prompt_action_up},
    {"\x1b[B", &prompt_action_down},
    {"\x1b[H", &prompt_action_home},
    {"\x1b[F", &prompt_action_end},
    {"\x7f", &prompt_action_backspace},
    {"\t", &prompt_action_tab},
    {"\x0C", &prompt_action_clear_term},
    {"\x03", &prompt_action_interrupt},
    {"\x01", &prompt_action_home},
    {"\x06", &prompt_action_right},
    {"\x02", &prompt_action_left},
    {"\x17", &prompt_action_cut_line},
    {"\x15", &prompt_action_clear_line},
    {"\x04", &prompt_action_end_of_file},
};

struct hasher *shell_alias_hash_create(void)
{
    struct hasher *hash = NULL;
    void *data = NULL;

    for (int i = 0; i < BINDKEY_COUNT; ++i) {
        data = (void *) strdup(BINDKEY_DICT[i].data);
        if (data == NULL) {
            return (NULL);
        }
        if (hasher_insert_data(
            &hash,
            strdup(BINDKEY_DICT[i].key),
            data
        )) {
            return (NULL);
        }
    }
    return (hash);
}
