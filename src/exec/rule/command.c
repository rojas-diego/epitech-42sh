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
    for (; rule; rule = rule->command) {
        if (rule->word) {
            exec_rule_debug(shell, "word", true);
            if (exec_rule_command_add_word(process, rule->word, shell->rawinput)) {
                return (EXEC_RULE_ALLOCATION_FAIL);
            }
            exec_rule_debug(shell, "word", false);
        } else if (rule->redirection) {
            if (exec_rule_command_add_redirection(job, rule->redirection, shell->rawinput)) {
                return (EXEC_RULE_AMBIGUOUS_REDIRECTION);
            }
        } else {
        }
    }
    job_process_append(job, process);
    exec_rule_debug(shell, "command", false);
    return (EXEC_RULE_SUCCESS);
}
