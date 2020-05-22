/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule control repeat
*/

#ifndef SH_SHELL_EXEC_RULE_CONTROL_REPEAT_H_
#define SH_SHELL_EXEC_RULE_CONTROL_REPEAT_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_control_repeat(
    struct sh *shell,
    struct expr_repeat_control_s *rule
);

#endif /* !SH_SHELL_EXEC_RULE_CONTROL_REPEAT_H_ */
