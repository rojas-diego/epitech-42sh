/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** term_init
*/

#include <sys/types.h>
#include <termios.h>

#include <unistd.h>
#include <curses.h>
/* setupterm */
#include <term.h>

#include "proto/shell/term_init.h"
#include "proto/sighandler.h"

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

static int term_job_init(struct sh *shell)
{
    pid_t shell_pgid = getpgrp();

    while (shell_pgid != tcgetpgrp(STDIN_FILENO)) {
        kill(-shell_pgid, SIGTTIN);
        shell_pgid = getpgrp();
    }
    term_set_signal_handling(SIG_IGN);
    shell->pgid = getpid();
    if (setpgid(shell_pgid, shell_pgid) < 0) {
        perror("Couldn't put the shell in its own process group");
        return (1);
    }
    tcsetpgrp(STDIN_FILENO, shell_pgid);
    return (0);
}

/*
** @DESCRIPTION
**   Initialises term && term keys.
*/
int term_init(struct sh *shell)
{
    const char *terminfo_str[] = {"cub1", "cuf1", "clear"};
    int erret = 0;

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
    term_job_init(shell);
    return (0);
}
