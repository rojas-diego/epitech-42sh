/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** get_input
*/

/* memset */
#include <string.h>
/* isprint */
#include <ctype.h>
/* malloc */
#include <stdlib.h>

#include "parser_toolbox/add_char.h"

#include "proto/shell.h"

#include "proto/prompt/rewrite_color_command.h"
#include "proto/prompt/read_single_input.h"
#include "proto/prompt/prompt_add_char.h"
#include "proto/prompt/wait_input.h"
#include "proto/prompt/set_raw_mode.h"

static int find_matching_action(struct sh *shell, char *buffer, size_t len)
{
    int j = 0;

    for (int i = 0; i < PROMPT_ACTION_COUNT; ++i) {
        if (strncmp(shell->prompt.action[i].key, buffer, len)) {
            continue;
        }
        if (!strcmp(shell->prompt.action[i].key, buffer)) {
            free(buffer);
            shell->prompt.action[i].action(shell);
            return (-1);
        }
        j = 1;
    }
    return (j == 0 ? -2 : 0);
}

static void update_input(char **buffer, size_t *len, size_t *size)
{
    wait_input();
    (*buffer)[*len] = read_single_input();
    *len += (*buffer)[*len] > 0;
    if (*len > *size - 2) {
        (*size) *= 2;
        *buffer = (char *) realloc((void *) *buffer, *size);
    }
}

static char *buffer_seq(struct sh *shell, char init)
{
    size_t size = 128;
    char *buffer = malloc(sizeof(char) * size);
    size_t len = 0;
    int match = -1;

    memset((void *) buffer, 0, size);
    if (init == -1)
        update_input(&buffer, &len, &size);
    else
        buffer[len++] = init;
    while (match != -2) {
        match = find_matching_action(shell, buffer, len);
        if (match == -1) {
            return (NULL);
        }
        if (match != -2) {
            update_input(&buffer, &len, &size);
        }
    }
    return (buffer);
}

static int add_input_or_execute_action(struct sh *shell, char character)
{
    char *buffer = NULL;

    if (character == '\n' || character == 0x00
    || (!shell->prompt.input[0] && character == 0x04)) {
        shell->active = !(character == 0x04);
        rewrite_color_command(shell);
        return (1);
    }
    buffer = buffer_seq(shell, character);
    if (!buffer) {
        return (0);
    }
    for (size_t i = 0; buffer[i] != '\0'; ++i) {
        if (isprint(buffer[i])) {
            prompt_add_char(shell, buffer[i]);
        }
    }
    free(buffer);
    return (0);
}

void get_input(struct sh *shell)
{
    char character = -1;

    if (shell->atty)
        term_set_raw_mode(&(shell->prompt.orig_term));
    while (character != '\n') {
        wait_input();
        character = read_single_input();
        if (character == -1) {
            if (shell->atty)
                continue;
            break;
        }
        if (add_input_or_execute_action(shell, character)) {
            break;
        }
    }
    if (shell->atty
    && tcsetattr(0, TCSANOW, &(shell->prompt.orig_term)) == -1) {
    }
}
