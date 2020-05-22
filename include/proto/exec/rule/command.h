/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule command
*/

#ifndef SH_SHELL_EXEC_RULE_COMMAND_H_
#define SH_SHELL_EXEC_RULE_COMMAND_H_

#include "types/shell.h"
#include "types/expr.h"
#include "types/job.h"

int exec_rule_command(
    struct sh *shell,
    struct expr_command_s *rule,
    struct job_s *job
);

#endif /* !SH_SHELL_EXEC_RULE_COMMAND_H_ */
