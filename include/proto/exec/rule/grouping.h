/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule grouping
*/

#ifndef SH_SHELL_EXEC_RULE_GROUPING_H_
#define SH_SHELL_EXEC_RULE_GROUPING_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_grouping(
    struct sh *shell,
    struct expr_grouping_s *rule,
    bool foreground
);

#endif /* !SH_SHELL_EXEC_RULE_GROUPING_H_ */
