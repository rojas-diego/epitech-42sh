/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** term_init
*/

#include <unistd.h>
#include <curses.h>
/* setupterm */
#include <term.h>

#include "proto/shell/term_init.h"

#include "constants/prompt/private_action.h"

/*
{"kent", &prompt_action_enter},
{"\x1b[5~", NULL}, // Super up history:
    take current command, go up until finding same (FN + ARROW_UP)
*/
static const struct {
    const char *name;
    prompt_action action;
} TERMINFO_KEY[PROMPT_ACTION_COUNT] = {
    {"kdch1", &prompt_action_delete},
    {"khome", &prompt_action_home},
    {"kend", &prompt_action_end},
    {"\x1b[D", &prompt_action_left},
    {"\x1b[C", &prompt_action_right},
    {"\x1b[A", &prompt_action_up},
    {"\x1b[B", &prompt_action_down},
    {"\x7f", &prompt_action_backspace},
    {"\t", &prompt_action_tab},
    {"\x0C", &prompt_action_clear_term},
    {"\x03", &prompt_action_interrupt},
    {"\x01", &prompt_action_home},
    {"\x06", &prompt_action_right},
    {"\x02", &prompt_action_left},
    {"\x1b[H", &prompt_action_home},
    {"\x1b[F", &prompt_action_end},
    {"\x17", &prompt_action_cut_line},
    {"\x15", &prompt_action_clear_line},
};

/* handle IOCTL ?
#include <sys/ioctl.h>
char *smkx;
char *rmkx;
int           ioctl;*

shell->prompt.smkx = tigetstr("smkx");
shell->prompt.rmkx = tigetstr("rmkx");
if (shell->prompt.smkx == (char *) -1) {
    shell->prompt.smkx = 0;
}
if (shell->prompt.rmkx == (char *) -1) {
    shell->prompt.rmkx = 0;
}

if (shell->ioctl && shell->prompt.smkx) {
putp(shell->prompt.smkx);
fflush(stdout);
}
if (shell->ioctl && shell->prompt.rmkx) {
putp(shell->prompt.rmkx);
fflush(stdout);
}
*/

/*
** @DESCRIPTION
**   Initialises term && term keys.
*/
static int term_init_actions(struct sh *shell)
{
    for (int i = 0; i < PROMPT_ACTION_COUNT; ++i) {
        shell->prompt.action[i] = (struct prompt_action) {
            .action = TERMINFO_KEY[i].action,
            .key = i > 2 ? TERMINFO_KEY[i].name
                : tigetstr(TERMINFO_KEY[i].name)
        };
        if (i < 3 && shell->prompt.action[i].key == (char *) -1) {
            return (1);
        }
    }
    return (0);
}

/*
** @DESCRIPTION
**   Initialises term && term keys.
*/
int term_init(struct sh *shell)
{
    const char *terminfo_str[] = {"cub1", "cuf1", "clear"};
    int erret;

    if (!shell->atty) {
        return (0);
    }
    if (setupterm(NULL, 1, &erret) == ERR) {
        return (1);
    }
    for (int i = 0; i < PROMPT_EFFECT_COUNT; ++i) {
        shell->prompt.effect[i] = tigetstr(terminfo_str[i]);
        if (shell->prompt.effect[i] == (char *) -1) {
            return (1);
        }
    }
    if (tcgetattr(0, &shell->prompt.orig_term) == -1) {
        return (1);
    }
    return (term_init_actions(shell));
}
