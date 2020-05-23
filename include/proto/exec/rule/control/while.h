/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule control while
*/

#ifndef SH_SHELL_EXEC_RULE_CONTROL_WHILE_H_
#define SH_SHELL_EXEC_RULE_CONTROL_WHILE_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_control_while(
    struct sh *shell,
    struct expr_while_control_s *rule
);

#endif /* !SH_SHELL_EXEC_RULE_CONTROL_WHILE_H_ */
