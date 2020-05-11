/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec simple_exec
*/

#ifndef SH_SHELL_EXEC_SIMPLE_EXEC_H_
#define SH_SHELL_EXEC_SIMPLE_EXEC_H_

#include <wordexp.h>

#include "types/shell.h"

void simple_exec(struct sh *sh, wordexp_t *we);

#endif /* !SH_SHELL_EXEC_SIMPLE_EXEC_H_ */
