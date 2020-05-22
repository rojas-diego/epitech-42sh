/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** sig handler
*/

#include "proto/sighandler.h"

static const int SIGCOUNT = 5;

static const int SIGNUMS[] = {
    SIGINT, SIGQUIT, SIGTSTP, SIGTTIN, SIGTTOU, SIGCHLD
};

void term_set_signal_handling(sighandler_t action)
{
    for (int i = 0; i < SIGCOUNT; ++i) {
        signal(SIGNUMS[i], action);
    }
}
