/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec rule pipeline
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "proto/exec/rule/debug.h"
#include "types/exec/rule.h"

#include "proto/job/create.h"
#include "proto/job/destroy.h"
#include "proto/job/launch.h"
#include "proto/exec/rule/command.h"
#include "proto/exec/rule/subshell.h"
#include "proto/exec/rule/pipeline.h"
#include "parser_toolbox/string_split.h"
#include "parser_toolbox/argv_length.h"
#include "hasher/get_data.h"
#include "types/builtins.h"

void follow_alias(
    struct process_s **process,
    struct process_s **save,
    char *data
)
{
    if (data != (*process)->argv[0]) {
        replace_add_data(*process, data);
        *process = *save;
    } else {
        *save = *process;
        *process = (*process)->next;
    }
}
