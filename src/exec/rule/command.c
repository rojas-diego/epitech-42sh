/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule command
*/

#include "proto/exec/rule/debug.h"
#include "types/exec/rule.h"

#include "proto/job/process/create.h"
#include "proto/job/process/append.h"
#include "proto/exec/rule/command/add_word.h"
#include "proto/exec/rule/command/add_redirection.h"
#include "proto/exec/rule/command.h"
#include "proto/exec/magic/parse.h"

int exec_rule_command(
    struct sh *shell,
    struct expr_command_s *rule,
    struct job_s *job
)
{
    struct process_s *process = process_create();

    exec_rule_debug(shell, "command", true);
    if (!process) {
        return (EXEC_RULE_ALLOCATION_FAIL);
    }
    if (do_post_process_command(shell, process, rule)) {
        return (EXEC_RULE_ALLOCATION_FAIL);
    }
    for (; rule; rule = rule->command) {
        if (!rule->redirection) {
            continue;
        }
        if (exec_rule_command_add_redirection(
        job, rule->redirection, shell->rawinput)) {
            return (EXEC_RULE_REDIRECTION_FAIL);
        }
    }
    job_process_append(job, process);
    exec_rule_debug(shell, "command", false);
    return (EXEC_RULE_SUCCESS);
}
