/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/control/if.h"
#include "proto/exec/rule/control/while.h"
#include "proto/exec/rule/control/foreach.h"
#include "proto/exec/rule/control/repeat.h"
#include "proto/exec/rule/control.h"

int exec_rule_control(
    struct sh *shell,
    struct expr_control_s *rule
)
{
    exec_rule_debug(shell, "control", true);
    if (rule->if_control) {
        exec_rule_control_if(shell, rule->if_control);
    }
    if (rule->while_control) {
        exec_rule_control_while(shell, rule->while_control);
    }
    if (rule->foreach_control) {
        exec_rule_control_foreach(shell, rule->foreach_control);
    }
    if (rule->repeat_control) {
        exec_rule_control_repeat(shell, rule->repeat_control);
    }
    exec_rule_debug(shell, "control", false);
    return (0);
}
