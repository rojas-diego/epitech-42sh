/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** set_raw_mode
*/

/* STDIN_FILENO */
#include <unistd.h>

/* tcsetattr */
#include <termios.h>

#include "proto/prompt/set_raw_mode.h"

void term_set_raw_mode(struct termios *orig_term)
{
    struct termios new_term;

    new_term = *orig_term;
    new_term.c_cc[VTIME] = 0;
    new_term.c_cc[VMIN] = 0;
    new_term.c_lflag &= (tcflag_t) ~(ECHO | ICANON | ISIG);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &new_term) == -1) {
    }
}
