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
#include "parser_toolbox/word_array_chr.h"

#include "path_iteration.h"

#include "proto/prompt/input/add_string.h"
#include "proto/prompt/input/add_char.h"
#include "proto/prompt/input/reprint_input.h"
#include "proto/prompt/action/tab.h"
#include "proto/prompt/display.h"

static void prompt_action_tab_extend_glob(
    struct sh *shell,
    wordexp_t *we,
    char *str
)
{
    enum parser_toolbox_e ret;
    char **copy = NULL;

    if (we->we_wordc == 1) {
        ret = ptb_isdir(we->we_wordv[0]);
        if (ret == PTB_FAILURE) {
            return;
        }
        prompt_input_add_string(shell, we->we_wordv[0] + strlen(str) - 1);
        prompt_input_add_char(shell, (ret) ? '/' : ' ');
    } else {
        copy = ptb_word_array_rchr(we->we_wordv, we->we_wordc, '/');
        puts("");
        ptb_display_sorted_strings_equalize(copy, we->we_wordc, 132);
        prompt_display(shell);
        prompt_reprint_input(&(shell->prompt));
        free(copy);
    }
}

static void prompt_action_tab_extend_glob_from_env_path(
    struct sh *shell,
    char *str
)
{
    int is_path = strchr(str, '/') != NULL;
    const char *path_env = !is_path ? getenv("PATH") : NULL;
    const char *path = path_env ? path_iteration(path_env) : NULL;
    wordexp_t we = {0};

    if (wordexp(str, &we, 0))
        return;
    for (; *str != '*' && !is_path && path; path = path_iteration(path_env)) {
        size_t len = strlen(path) + 2 + strlen(str);
        char *tmp = malloc(len);
        strncpy(tmp, path, len);
        strcat(tmp, "/");
        strcat(tmp, str);
        if (wordexp(tmp, &we, WRDE_APPEND)) {
            free(tmp);
            return;
        }
        if (ptb_isdir(we.we_wordv[we.we_wordc - 1]) == PTB_FAILURE) {
            we.we_wordc -= 1;
            free(we.we_wordv[we.we_wordc]);
            we.we_wordv[we.we_wordc] = NULL;
        }
        free(tmp);
    }
    prompt_action_tab_extend_glob(shell, &we, str);
    wordfree(&we);
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
    start = (unsigned int) (str ? (str - shell->prompt.input) + 1 : 0);
    str = ptb_sub_string(shell->prompt.input, start, shell->prompt.cursor);
    if (str == NULL)
        return;
    shell->prompt.input[shell->prompt.cursor] = save;
    str[shell->prompt.cursor - start] = '*';
    prompt_action_tab_extend_glob_from_env_path(shell, str);
    free(str);
}
