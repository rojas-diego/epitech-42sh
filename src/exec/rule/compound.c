/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule block
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/grouping.h"
#include "proto/exec/rule/jobs.h"
#include "proto/exec/rule/compound.h"

int exec_rule_compound(
    struct sh *shell,
    struct expr_compound_s *rule
)
{
    exec_rule_debug(shell, "compound", true);
    exec_rule_grouping(
        shell, rule->grouping, rule->jobs ? !rule->jobs->ampersand : true
    );
    if (rule->jobs) {
        exec_rule_jobs(shell, rule->jobs, !rule->ampersand_end);
    }
    exec_rule_debug(shell, "compound", false);
    return (0);
}
