/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule command add_redirection
*/

#ifndef SH_SHELL_EXEC_RULE_COMMAND_ADD_REDIRECTION_H_
#define SH_SHELL_EXEC_RULE_COMMAND_ADD_REDIRECTION_H_

#include "types/job.h"
#include "types/expr.h"

int exec_rule_command_add_redirection(
    struct job_s *job,
    struct expr_redirection_s *redirection,
    const char *input
);

#endif /* !SH_SHELL_EXEC_RULE_COMMAND_ADD_REDIRECTION_H_ */
