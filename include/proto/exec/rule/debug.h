/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule debug
*/

#ifndef SH_SHELL_EXEC_RULE_DEEBUG_H_
#define SH_SHELL_EXEC_RULE_DEEBUG_H_

#include "types/shell.h"

void exec_rule_debug(struct sh *shell, const char *rule, bool entering);

void exec_rule_job_display(struct sh *shell, struct job_s *job);

#endif /* !SH_SHELL_EXEC_RULE_DEEBUG_H_ */
