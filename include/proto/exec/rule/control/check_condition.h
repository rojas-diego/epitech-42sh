/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule control check_condition
*/

#ifndef SH_SHELL_EXEC_RULE_CONTROL_CHECK_CONDITION_H_
#define SH_SHELL_EXEC_RULE_CONTROL_CHECK_CONDITION_H_

#include "types/shell.h"
#include "types/expr.h"

_Bool exec_rule_control_check_condition(
    struct sh *shell,
    struct expr_wordlist_expression_s *word
);

#endif /* !SH_SHELL_EXEC_RULE_CONTROL_CHECK_CONDITION_H_ */
