/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule control else
*/

#ifndef SH_SHELL_EXEC_RULE_CONTROL_ELSE_H_
#define SH_SHELL_EXEC_RULE_CONTROL_ELSE_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_control_else(
    struct sh *shell,
    struct expr_else_control_s *rule
);

#endif /* !SH_SHELL_EXEC_RULE_CONTROL_ELSE_H_ */
