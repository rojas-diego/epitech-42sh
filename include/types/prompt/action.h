/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** sh prompt action
*/

#ifndef SH_PROMPT_ACTION_H_
#define SH_PROMPT_ACTION_H_

/* const int PROMPT_ACTION_COUNT; */
enum prompt_action_e {
    PROMPT_ACTION_COUNT = 19
};

typedef struct sh sh_t;

typedef void (*prompt_action)(sh_t *shell);

struct prompt_action_s
{
    const char *key;
    prompt_action action;
};

#endif /* !SH_PROMPT_ACTION_H_ */
