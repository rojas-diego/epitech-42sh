/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule pipeline
*/

#ifndef SH_SHELL_EXEC_RULE_PIPELINE_H_
#define SH_SHELL_EXEC_RULE_PIPELINE_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_pipeline(
    struct sh *shell,
    struct expr_pipeline_s *rule
);

#endif /* !SH_SHELL_EXEC_RULE_PIPELINE_H_ */
