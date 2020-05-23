/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control foreach
*/

#include <stddef.h>

#include "proto/shell/local_variables.h"

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/block.h"
#include "proto/exec/rule/control/foreach.h"

char *token_get_string(const struct token_s *this, const char *rawinput);

int exec_rule_control_foreach(
    struct sh *shell,
    struct expr_foreach_control_s *rule
)
{
    char *substr = token_get_string(rule->word, shell->rawinput);
    char *words[] = {"1", "2"};//
    size_t len = 2;

    exec_rule_debug(shell, "foreach", true);
    local_variable_from_data(shell->local_var, substr, "\0");
    for (size_t i = 0; i < len; ++i) {
        local_variable_from_data(shell->local_var, substr, words[i]);
        exec_rule_block(shell, rule->block);
    }
    exec_rule_debug(shell, "foreach", false);
    return (0);
}
