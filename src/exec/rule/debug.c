/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule program
*/

#include <stdio.h>

#include "proto/exec/rule/debug.h"

void exec_rule_debug(struct sh *shell, const char *rule, bool entering)
{
    if (!shell->debug_mode) {
        return;
    }
    shell->debug.depth += entering;
    dprintf(2, "\033[0m\033[38;2;230;70;100m");
    for (int i = 1; i < shell->debug.depth; i++) {
        dprintf(2, "│   ");
    }
    if (entering) {
        dprintf(2, "┌─o \033[1m\033[38;2;150;150;220m%s\033[0m\n", rule);
    } else {
        shell->debug.depth -= 1;
        dprintf(2, "└─o \033[1m\033[38;2;150;150;220m%s\033[0m\n", rule);
    }
}
