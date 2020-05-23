/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule command add_word
*/

#ifndef SH_SHELL_EXEC_RULE_COMMAND_ADD_WORD_H_
#define SH_SHELL_EXEC_RULE_COMMAND_ADD_WORD_H_

#include "types/job.h"
#include "types/token.h"

int exec_rule_command_add_word(
    struct process_s *process,
    struct token_s *word,
    const char *input
);

#endif /* !SH_SHELL_EXEC_RULE_COMMAND_ADD_WORD_H_ */
