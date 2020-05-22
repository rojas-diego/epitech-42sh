/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule grouping
*/

#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/grouping.h"
#include "proto/exec/rule/jobs.h"

int exec_rule_jobs(
    struct sh *shell,
    struct expr_jobs_s *rule,
    bool foreground
)
{
    exec_rule_debug(shell, "jobs", true);
    for (; rule->jobs; rule = rule->jobs) {
        exec_rule_grouping(shell, rule->grouping, !rule->jobs);
    }
    exec_rule_grouping(shell, rule->grouping, foreground);
    exec_rule_debug(shell, "jobs", false);
    return (0);
}
