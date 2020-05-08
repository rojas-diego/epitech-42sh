/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** Constants private_action
*/

#ifndef SH_CONSTANTS_PROMPT_PRIVATE_ACTION_H_
#define SH_CONSTANTS_PROMPT_PRIVATE_ACTION_H_

#include "proto/prompt/action.h"

const int PROMPT_ACTION_COUNT = 11;

static const struct {
    char *name;
    prompt_action action;
} TERMINFO_KEY[11] = {
    {"kcub1", &prompt_action_left},
    {"kcuf1", &prompt_action_right},
    {"kcuu1", &prompt_action_up},
    {"kcud1", &prompt_action_down},
    {"kdch1", &prompt_action_delete},
    {"kbs", &prompt_action_backspace},
    {"khome", &prompt_action_home},
    {"kend", &prompt_action_end},
    //{"kent", &prompt_action_enter},
    //{"kLFT", &prompt_action_shift_left},
    //{"kRIT", &prompt_action_shift_right},
    {"\t", &prompt_action_tab},
    {"\x0C", &prompt_action_clear_term},
    {"\x03", &prompt_action_interrupt},
    //{"x01", &prompt_action_start}
};

#endif
