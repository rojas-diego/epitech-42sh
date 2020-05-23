/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule control foreach
*/

#ifndef SH_SHELL_EXEC_RULE_CONTROL_FOREACH_H_
#define SH_SHELL_EXEC_RULE_CONTROL_FOREACH_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_control_foreach(
    struct sh *shell,
    struct expr_foreach_control_s *rule
);

#endif /* !SH_SHELL_EXEC_RULE_CONTROL_FOREACH_H_ */
