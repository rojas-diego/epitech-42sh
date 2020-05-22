/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule command
*/

#include <stdlib.h>
#include <string.h>

#include "parser_toolbox/sub_string.h"

#include "types/exec/rule.h"

#include "proto/exec/rule/command/add_word.h"

int exec_rule_command_add_word(
    struct process_s *process,
    struct token_s *word,
    const char *input
)
{
    char *substr = ptb_sub_string(input, word->start, word->end + 2);

    if (!substr) {
        return (EXEC_RULE_ALLOCATION_FAIL);
    }
    // parse substring
    if (process->argc + 1 >= process->max_argc) {
        process->max_argc *= 2;
        process->argv = realloc(process->argv, process->max_argc);
        memset(process->argv + process->argc + 1, 0, process->argc + 1);
    }
    process->argv[process->argc++] = substr;
    printf("%zu, %s\n", process->argc, process->argv[process->argc++]);
    return (EXEC_RULE_SUCCESS);
}
