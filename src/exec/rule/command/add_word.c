/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule command
*/

#include <stdlib.h>
#include <string.h>

#include "types/exec/rule.h"

#include "proto/exec/rule/command/add_word.h"

//printf("%zu, %s\n", process->argc, process->argv[process->argc++]);
char *token_get_string(const struct token_s *this, const char *rawinput);
// parse substring
int exec_rule_command_add_word(
    struct process_s *process,
    struct token_s *word,
    const char *input
)
{
    char *substr = token_get_string(word, input);

    if (!substr) {
        return (EXEC_RULE_ALLOCATION_FAIL);
    }
    if (process->argc + 1 >= process->max_argc) {
        process->max_argc *= 2;
        process->argv = realloc(process->argv, process->max_argc);
        memset(process->argv + process->argc + 1, 0, process->argc + 1);
    }
    process->argv[process->argc++] = substr;
    return (EXEC_RULE_SUCCESS);
}
