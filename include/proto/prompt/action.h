/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** sh prompt action
*/

#ifndef SH_PROTO_PROMPT_ACTION_H_
#define SH_PROTO_PROMPT_ACTION_H_

#include "types/shell.h"

void prompt_add_char(struct sh *shell, char c);
void prompt_update_cursor_pos(struct prompt *prompt);

void prompt_action_left(struct sh *shell);
void prompt_action_right(struct sh *shell);
void prompt_action_up(struct sh *shell);
void prompt_action_down(struct sh *shell);
void prompt_action_backspace(struct sh *shell);
void prompt_action_clear_term(struct sh *shell);
void prompt_action_home(struct sh *shell);
void prompt_action_delete(struct sh *shell);
void prompt_action_end(struct sh *shell);
void prompt_action_interrupt(struct sh *shell);
void prompt_action_tab(struct sh *shell);

#endif /* !SH_PROTO_PROMPT_ACTION_H_ */
