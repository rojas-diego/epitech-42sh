/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell exec rule program
*/

#ifndef SH_SHELL_EXEC_RULE_PROGRAM_H_
#define SH_SHELL_EXEC_RULE_PROGRAM_H_

#include "types/shell.h"
#include "types/expr.h"

int exec_rule_program(
    struct sh *shell,
    struct expr_program_s *rule
);

#endif /* !SH_SHELL_EXEC_RULE_PROGRAM_H_ */
