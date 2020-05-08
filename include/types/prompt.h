/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** sh prompt
*/

#ifndef SH_PROMPT_H_
#define SH_PROMPT_H_

#include <stddef.h>

#include <termios.h>

#include "types/prompt/action.h"
#include "types/prompt/effect.h"

struct prompt
{
    char input[8192];
    size_t cursor;
    const char *effect[PROMPT_EFFECT_COUNT];
    struct prompt_action action[11];
    struct termios oterm;
};

#endif /* !SH_PROMPT_H_ */
