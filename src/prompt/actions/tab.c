/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action tab
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wordexp.h>

#include "parser_toolbox/consts.h"
#include "parser_toolbox/strrpbrk.h"
#include "parser_toolbox/sub_string.h"
#include "parser_toolbox/includes.h"
#include "parser_toolbox/isdir.h"
#include "parser_toolbox/display_strings_equalize.h"

#include "proto/prompt/input/add_string.h"
#include "proto/prompt/input/add_char.h"
#include "proto/prompt/input/reprint_input.h"
#include "proto/prompt/action/tab.h"
#include "proto/prompt/display.h"

static void prompt_action_tab_extend_glob(struct sh *shell, char *str)
{
    wordexp_t we = {0};

    if (wordexp(str, &we, 0)) {
        return;
    }
    if (we.we_wordc == 1) {
        prompt_input_add_string(shell, we.we_wordv[0] + strlen(str) - 2);
        prompt_input_add_char(shell, (ptb_isdir(we.we_wordv[0])) ? '/' : ' ');
    } else {
        puts("");
        ptb_display_sorted_strings_equalize(we.we_wordv, we.we_wordc, 132);
        prompt_display(shell);
        prompt_reprint_input(&(shell->prompt));
    }
    wordfree(&we);
}

static void prompt_action_tab_extend_glob_from_env_path(
    __attribute__((unused)) struct sh *shell,
    __attribute__((unused)) char *str
)
{
    for (; 0;) {
    }
    return;
}

/*
//if (!str[1]) { || ptb_includes('/', str)
//    prompt_action_tab_extend_glob(shell, str);
// } else {
//     prompt_action_tab_extend_glob_from_env_path(shell, str);
// }
*/
void prompt_action_tab(struct sh *shell)
{
    char save = shell->prompt.input[shell->prompt.cursor];
    char *str = NULL;
    size_t start = 0;

    if (!shell->atty)
        return;
    shell->prompt.input[shell->prompt.cursor] = '\0';
    str = ptb_strrpbrk(shell->prompt.input, PTB_WHITESPACES);
    start = str ? (str - shell->prompt.input) : 0;
    str = ptb_sub_string(shell->prompt.input, start, shell->prompt.cursor);
    if (str == NULL)
        return;
    shell->prompt.input[shell->prompt.cursor] = save;
    str[shell->prompt.cursor - start] = '*';
    prompt_action_tab_extend_glob(shell, str);
    free(str);
}
