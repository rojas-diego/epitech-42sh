/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control repeat
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/grouping.h"
#include "proto/exec/rule/control/repeat.h"

int exec_rule_control_repeat(
    struct sh *shell,
    struct expr_repeat_control_s *rule
)
{
    //get repeat num
    long int repeat = 3;//exec_rule_control_repeat_get_number(rule->word);

    exec_rule_debug(shell, "repeat", true);
    for (long int i = 0; i < repeat; ++i) {
        exec_rule_grouping(shell, rule->grouping, false);
    }
    exec_rule_debug(shell, "repeat", false);
    return (0);
}
