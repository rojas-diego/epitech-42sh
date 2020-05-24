/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule control check_condition
*/

#include <stdlib.h>
#include <string.h>

#include "types/token.h"
#include "proto/exec/rule/debug.h"

#include "proto/exec/rule/block.h"
#include "proto/exec/rule/control/else.h"
#include "proto/exec/rule/control/check_condition.h"
#include "parser_toolbox/includes.h"
#include "parser_toolbox/consts.h"
#include "parser_toolbox/whitelist.h"

int magic_env_var_replace(struct sh *shell, char **str);

static char peek(char **str)
{
    return (**str);
}

static char get(char **str)
{
    if (!**str) {
        return ('\0');
    }
    return (*(*str)++);
}

static long int do_number(char **str, __attribute__((unused)) int *error)
{
    long int result = get(str) - '0';

    while (peek(str) >= '0' && peek(str) <= '9') {
        result = 10 * result + get(str) - '0';
    }
    return (result);
}

static long int do_equality(char **str, int *error)
{
    long int result = do_number(str, error);

    while (peek(str) == ' ' || peek(str) == '\t')
        get(str);
    for (char c; (peek(str) == '=' || peek(str) == '!')
    && *(*str + 1) == '=';) {
        c = get(str);
        if (c == '=' && get(str))
            result = result == do_equality(str, error);
        if (c == '!' && get(str))
            result = result != do_equality(str, error);
        while (peek(str) == ' ' || peek(str) == '\t')
            get(str);
    }
    return (result);
}

int exec_rule_control_check_condition(
    struct sh *shell,
    struct expr_wordlist_expression_s *w
)
{
    int error = 0;
    char *str = strndup(shell->rawinput + w->lparanth->end, w->rparanth->start -
        w->lparanth->end);
    char *cpy = str;
    long int a = 0;

    if (magic_env_var_replace(shell, &str)) {
        return (-1);
    }
    a = do_equality(&str, &error);
    exec_rule_debug(shell, "check_condition", true);
    if (error || !ptb_whitelist(str, PTB_WHITESPACES)) {
        free(cpy);
        dprintf(2, "if: Expression Syntax.\n");
        return (-1);
    }
    free(cpy);
    exec_rule_debug(shell, "check_condition", false);
    return (a ? 1 : 0);
}
