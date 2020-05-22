/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule jobs
*/

#ifndef SH_SHELL_EXEC_RULE_JOBS_H_
#define SH_SHELL_EXEC_RULE_JOBS_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_jobs(
    struct sh *shell,
    struct expr_jobs_s *rule
);

#endif /* !SH_SHELL_EXEC_RULE_JOBS_H_ */
