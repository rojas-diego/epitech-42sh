/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule subshell
*/

#ifndef SH_SHELL_EXEC_RULE_SUBSHELL_H_
#define SH_SHELL_EXEC_RULE_SUBSHELL_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_subshell(
    struct sh *shell,
    struct expr_subshell_s *rule,
    struct job_s *job
);

#endif /* !SH_SHELL_EXEC_RULE_SUBSHELL_H_ */
