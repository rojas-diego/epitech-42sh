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
#include "constants/prompt/private_bindkey_init.h"

static const int BINDKEY_COUNT = 19;

/*
{"kent", &prompt_action_enter},
{"\x1b[5~", NULL}, // Super up history:
    take current command, go up until finding same (FN + ARROW_UP)
*/
static const struct {
    const char *key;
    const struct {
        prompt_action func;
        const char *name;
    } data;
} BINDKEY_DICT[] = {
    {"kdch1",   {&prompt_action_delete,      ""}},
    {"khome",   {&prompt_action_home,        ""}},
    {"kend",    {&prompt_action_end,         ""}},
    {"\x1b[D",  {&prompt_action_left,        ""}},
    {"\x1b[C",  {&prompt_action_right,       ""}},
    {"\x1b[A",  {&prompt_action_up,          "up-history"}},
    {"\x1b[B",  {&prompt_action_down,        "down-history"}},
    {"\x1b[H",  {&prompt_action_home,        ""}},
    {"\x1b[F",  {&prompt_action_end,         ""}},
    {"\x7f",    {&prompt_action_backspace,   ""}},
    {"\t",      {&prompt_action_tab,         ""}},
    {"\x0C",    {&prompt_action_clear_term,  "clear-screen"}},
    {"\x03",    {&prompt_action_interrupt,   ""}},
    {"\x01",    {&prompt_action_home,        ""}},
    {"\x06",    {&prompt_action_right,       ""}},
    {"\x02",    {&prompt_action_left,        ""}},
    {"\x17",    {&prompt_action_cut_line,    ""}},
    {"\x15",    {&prompt_action_clear_line,  ""}},
    {"\x04",    {&prompt_action_end_of_file, ""}},
    {"\x1b[5~", {NULL,                       ""}},
    /* Standard key bindings */
    // {"^@",  {&action_set_mark_command,           "set-mark-command"}},
    // {"^A",  {&action_beginning_of_line,          "beginning-of-line"}},
    // {"^B",  {&action_backward_char,              "backward-char"}},
    // {"^C",  {&action_tty_sigintr,                "tty-sigintr"}},
    // {"^D",  {&action_delete_char_or_list_or_eof, "delete-char-or-list-or-eof"}},
    // {"^E",  {&action_end_of_line,                "end-of-line"}},
    // {"^F",  {&action_forward_char,               "forward-char"}},
    // {"^G",  {&action_is undefined,               "is undefined"}},
    // {"^H",  {&action_backward_delete_char,       "backward-delete-char"}},
    // {"^I",  {&action_complete_word,              "complete-word"}},
    // {"^J",  {&action_newline,                    "newline"}},
    // {"^K",  {&action_kill_line,                  "kill-line"}},
    // {"^L",  {&action_clear_screen,               "clear-screen"}},
    // {"^M",  {&action_newline,                    "newline"}},
    // {"^N",  {&action_down_history,               "down-history"}},
    // {"^O",  {&action_tty_flush_output,           "tty-flush-output"}},
    // {"^P",  {&action_up_history,                 "up-history"}},
    // {"^Q",  {&action_tty_start_output,           "tty-start-output"}},
    // {"^R",  {&action_i_search_back,              "i-search-back"}},
    // {"^S",  {&action_tty_stop_output,            "tty-stop-output"}},
    // {"^T",  {&action_transpose_chars,            "transpose-chars"}},
    // {"^U",  {&action_kill_whole_line,            "kill-whole-line"}},
    // {"^V",  {&action_quoted_insert,              "quoted-insert"}},
    // {"^W",  {&action_kill_region,                "kill-region"}},
    // {"^X",  {&action_sequence_lead_in,           "sequence-lead-in"}},
    // {"^Y",  {&action_yank,                       "yank"}},
    // {"^Z",  {&action_tty_sigtsusp,               "tty-sigtsusp"}},
    // {"^[",  {&action_sequence_lead_in,           "sequence-lead-in"}},
    // {"^\\", {&action_tty_sigquit,                "tty-sigquit"}},
    // {"^]",  {&action_tty_dsusp,                  "tty-dsusp"}},
    // {"^?",  {&action_backward_delete_char,       "backward-delete-char"}},
    // {"^�",  {&action_list_choices,               "list-choices"}},
    // {"^�",  {&action_backward_delete_word,       "backward-delete-word"}},
    // {"^�",  {&action_complete_word,              "complete-word"}},
    // {"^�",  {&action_clear_screen,               "clear-screen"}},
    // {"^�",  {&action_run_fg_editor,              "run-fg-editor"}},
    // {"^�",  {&action_complete_word,              "complete-word"}},
    // {"^�",  {&action_copy_prev_word,             "copy-prev-word"}},
    /*{" " , {/"    ->  self-insert-command,              ""},
    {"0" , {9"    ->  digit,                ""},
    {":" , {~"    ->  self-insert-command,                },*/
    /* Alternative key bindings */
    /* Multi-character bindings */
    // {"^[[A",  {&action_up_history,              "up-history"}},
    // {"^[[B",  {&action_down_history,            "down-history"}},
    // {"^[[C",  {&action_forward_char,            "forward-char"}},
    // {"^[[D",  {&action_backward_char,           "backward-char"}},
    // {"^[[H",  {&action_beginning_of_line,       "beginning-of-line"}},
    // {"^[[F",  {&action_end_of_line,             "end-of-line"}},
    // {"^[[3~", {&action_delete_char,             "delete-char"}},
    // {"^[OA",  {&action_up_history,              "up-history"}},
    // {"^[OB",  {&action_down_history,            "down-history"}},
    // {"^[OC",  {&action_forward_char,            "forward-char"}},
    // {"^[OD",  {&action_backward_char,           "backward-char"}},
    // {"^[OH",  {&action_beginning_of_line,       "beginning-of-line"}},
    // {"^[OF",  {&action_end_of_line,             "end-of-line"}},
    // {"^[^D",  {&action_list_choices,            "list-choices"}},
    // {"^[^H",  {&action_backward_delete_word,    "backward-delete-word"}},
    // {"^[^I",  {&action_complete_word,           "complete-word"}},
    // {"^[^L",  {&action_clear_screen,            "clear-screen"}},
    // {"^[^Z",  {&action_run_fg_editor,           "run-fg-editor"}},
    // {"^[^[",  {&action_complete_word,           "complete-word"}},
    // {"^[^_",  {&action_copy_prev_word,          "copy-prev-word"}},
    // {"^[ ",   {&action_expand_history,          "expand-history"}},
    // {"^[!",   {&action_expand_history,          "expand-history"}},
    // {"^[$",   {&action_spell_line,              "spell-line"}},
    // {"^[/",   {&action_dabbrev_expand,          "dabbrev-expand"}},
    // {"^[0",   {&action_digit_argument,          "digit-argument"}},
    // {"^[1",   {&action_digit_argument,          "digit-argument"}},
    // {"^[2",   {&action_digit_argument,          "digit-argument"}},
    // {"^[3",   {&action_digit_argument,          "digit-argument"}},
    // {"^[4",   {&action_digit_argument,          "digit-argument"}},
    // {"^[5",   {&action_digit_argument,          "digit-argument"}},
    // {"^[6",   {&action_digit_argument,          "digit-argument"}},
    // {"^[7",   {&action_digit_argument,          "digit-argument"}},
    // {"^[8",   {&action_digit_argument,          "digit-argument"}},
    // {"^[9",   {&action_digit_argument,          "digit-argument"}},
    // {"^[?",   {&action_which_command,           "which-command"}},
    // {"^[A",   {&action_newline_and_hold,        "newline-and-hold"}},
    // {"^[B",   {&action_backward_word,           "backward-word"}},
    // {"^[C",   {&action_capitalize_word,         "capitalize-word"}},
    // {"^[D",   {&action_delete_word,             "delete-word"}},
    // {"^[F",   {&action_forward_word,            "forward-word"}},
    // {"^[H",   {&action_run_help,                "run-help"}},
    // {"^[L",   {&action_downcase_word,           "downcase-word"}},
    // {"^[N",   {&action_history_search_forward,  "history-search-forward"}},
    // {"^[P",   {&action_history_search_backward, "history-search-backward"}},
    // {"^[R",   {&action_toggle_literal_history,  "toggle-literal-history"}},
    // {"^[S",   {&action_spell_word,              "spell-word"}},
    // {"^[U",   {&action_upcase_word,             "upcase-word"}},
    // {"^[W",   {&action_copy_region_as_kill,     "copy-region-as-kill"}},
    // {"^[Y",   {&action_yank_pop,                "yank-pop"}},
    // {"^[_",   {&action_insert_last_word,        "insert-last-word"}},
    // {"^[a",   {&action_newline_and_hold,        "newline-and-hold"}},
    // {"^[b",   {&action_backward_word,           "backward-word"}},
    // {"^[c",   {&action_capitalize_word,         "capitalize-word"}},
    // {"^[d",   {&action_delete_word,             "delete-word"}},
    // {"^[f",   {&action_forward_word,            "forward-word"}},
    // {"^[h",   {&action_run_help,                "run-help"}},
    // {"^[l",   {&action_downcase_word,           "downcase-word"}},
    // {"^[n",   {&action_history_search_forward,  "history-search-forward"}},
    // {"^[p",   {&action_history_search_backward, "history-search-backward"}},
    // {"^[r",   {&action_toggle_literal_history,  "toggle-literal-history"}},
    // {"^[s",   {&action_spell_word,              "spell-word"}},
    // {"^[u",   {&action_upcase_word,             "upcase-word"}},
    // {"^[w",   {&action_copy_region_as_kill,     "copy-region-as-kill"}},
    // {"^[y",   {&action_yank_pop,                "yank-pop"}},
    // {"^[^?",  {&action_backward_delete_word,    "backward-delete-word"}},
    // {"^X^X",  {&action_exchange_point_and_mark, "exchange-point-and-mark"}},
    // {"^X*",   {&action_expand_glob,             "expand-glob"}},
    // {"^X$",   {&action_expand_variables,        "expand-variables"}},
    // {"^XG",   {&action_list_glob,               "list-glob"}},
    // {"^Xg",   {&action_list_glob,               "list-glob"}},
    // {"^Xn",   {&action_normalize_path,          "normalize-path"}},
    // {"^XN",   {&action_normalize_path,          "normalize-path"}},
    // {"^X?",   {&action_normalize_command,       "normalize-command"}},
    // {"^X^I",  {&action_complete_word_raw,       "complete-word-raw"}},
    // {"^X^D",  {&action_list_choices_raw,        "list-choices-raw"}},
    /* Arrow key bindings */
    // {down,    {&action_down_history,            "down-history"}},
    // {up,      {&action_up_history,              "up-history"}},
    // {left,    {&action_backward_char,           "backward-char"}},
    // {right,   {&action_forward_char,            "forward-char"}},
    // {home,    {&action_beginning_of_line,       "beginning-of-line"}},
    // {end,     {&action_end_of_line,             "end-of-line"}},
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
            (void *) BINDKEY_DICT[i].data.func
        )) {
            return (NULL);
        }
    }
    return (hash);
}
