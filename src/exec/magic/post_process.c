/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** parse
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wordexp.h>

#include "proto/exec/rule/command.h"

#include "parser_toolbox/string_split.h"
#include "parser_toolbox/consts.h"
#include "parser_toolbox/unquote.h"

#include "proto/token/get_string.h"
#include "proto/exec/rule/command/add_word.h"
#include "proto/exec/magic/parse.h"

/*int do_merge(struct process_s *proc, char **to_merge, size_t index)
{
    size_t length = ptb_argv_length(to_merge);
    char **tmp = malloc(sizeof(char *) * (proc->argc - index + 1));

    if (!tmp)
        return (1);
    for (size_t i = index + 1; i < proc->argc; tmp[i - index - 1] = proc->argv[i]);
    tmp[proc->argc - index] = NULL;
    while (proc->argc + length >= proc->max_argc) {
        proc->max_argc *= 2;
        proc->argv = realloc(proc->argv, proc->max_argc);
        if (!proc->argv)
            return (1);
        memset(proc->argv + proc->argc + 1, 0, proc->argc + 1);
    }
    for (size_t i = 0; i < length; ++i)
        proc->argv[proc->argc++] = to_merge[i];
    for (size_t i = -1; tmp[++i]; proc->argv[proc->argc++] = tmp[i]);
    return (0);
}*/

static int tmp_exec_rule_command_add_word(
    struct process_s *process,
    char *word
)
{
    if (process->argc + 1 >= process->max_argc) {
        process->max_argc *= 2;
        process->argv = realloc(process->argv, process->max_argc);
        if (!process->argv) {
            return (1);
        }
        memset(process->argv + process->argc + 1, 0, process->argc + 1);
    }
    process->argv[process->argc++] = word;
    return (0);
}

char **do_post_process_glob(
    struct sh *shell,
    char **substr
)
{
    wordexp_t we = {0};
    char **strs = NULL;

    if (wordexp(*substr, &we, 0)) {
        return (NULL);
    }
    strs = calloc(we.we_wordc + 1, sizeof(char *));
    if (!strs)
        return (NULL);
    for (size_t i = 0; i < we.we_wordc; ++i) {
        strs[i] = strdup(we.we_wordv[i]);
        if (!strs[i])
            return (NULL);
    }
    wordfree(&we);
    return (strs);
}

char **do_post_process_word(
    struct sh *shell,
    char **substr
)
{
    char **strs = NULL;

    if (**substr == '`') {
        ptb_unquote(*substr);
        strs = do_subshelled_magic_quote(shell, *substr);
        return (strs);
    }
    if (magic_env_var_replace(shell, substr)) {
        *substr = NULL;
        return (NULL);
    }
    return (do_post_process_glob(shell, substr));
}

int do_post_process(
    struct sh *shell,
    struct process_s *proc,
    struct expr_wordlist_s *words
)
{
    char *substr = NULL;
    char **post_processed = NULL;

    for (; words; words = words->wordlist) {
        substr = token_get_string(words->word, shell->rawinput);
        post_processed = do_post_process_word(shell, &substr);
        for (size_t i = 0; post_processed[i]; ++i) {
            tmp_exec_rule_command_add_word(proc, post_processed[i]);
        }
        if (!post_processed) {
            if (!substr)
                return (1);
            tmp_exec_rule_command_add_word(proc, substr);
        }
    }
    return (0);
}

int do_post_process_command(
    struct sh *shell,
    struct process_s *proc,
    struct expr_command_s *command
)
{
    char *substr = NULL;
    char **post_processed = NULL;

    for (; command; command = command->command) {
        if (command->redirection)
            continue;
        substr = token_get_string(command->word, shell->rawinput);
        post_processed = do_post_process_word(shell, &substr);
        for (size_t i = 0; post_processed && post_processed[i]; ++i) {
            tmp_exec_rule_command_add_word(proc, post_processed[i]);
        }
        if (!post_processed) {
            if (substr == NULL)
                return (1);
            tmp_exec_rule_command_add_word(proc, substr);
        }
    }
    return (0);
}
