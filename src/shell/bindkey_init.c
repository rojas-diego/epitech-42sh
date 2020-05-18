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
#include "constants/prompt/private_action.h"

static const int BINDKEY_COUNT = 19;

/*
{"kent", &prompt_action_enter},
{"\x1b[5~", NULL}, // Super up history:
    take current command, go up until finding same (FN + ARROW_UP)
*/
static const struct {
    const char *key;
    prompt_action data;
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

struct hasher *shell_bindkey_hash_create(void)
{
    struct hasher *hash = NULL;
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
            (void *) BINDKEY_DICT[i].data
        )) {
            return (NULL);
        }
    }
    return (hash);
}
