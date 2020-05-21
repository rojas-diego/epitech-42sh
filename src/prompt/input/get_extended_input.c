/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** get_extended_input
*/

/* calloc && realloc */
#include <stdlib.h>
/* bool type */
#include <stdbool.h>
/* strcmp */
#include <string.h>

#include "proto/prompt/input/read_single_input.h"
#include "proto/prompt/input/wait_input.h"
#include "proto/prompt/set_raw_mode.h"
#include "proto/prompt/input/get_extended_input.h"

#include "types/builtins/bindkey.h"

static enum get_input_e find_action_match(
    struct sh *shell,
    char *buffer,
    size_t len
)
{
    bool still_matching = false;

    for (struct hasher *hash = shell->bindkey; hash; hash = hash->next) {
        if (strncmp(hash->key, buffer, len)) {
            continue;
        }
        if (!strcmp(hash->key, buffer)) {
            free(buffer);
            ((struct bindkey_s *) hash->data)->func(shell);
            return (GET_INPUT_ACTION_FOUND);
        }
        still_matching = true;
    }
    return (still_matching ? GET_INPUT_CONTINUE : GET_INPUT_NO_VALID_ACTION);
}

static enum get_input_e update_input(char **buffer, size_t *len, size_t *size)
{
    if (wait_input() == -1) {
        return (GET_INPUT_WAIT_FAIL);
    }
    if (read_single_input(&((*buffer)[*len])) != GET_INPUT_CONTINUE) {
        return (GET_INPUT_READ_FAIL);
    }
    *len += (*buffer)[*len] > 0;
    if (*len > *size - 2) {
        (*size) *= 2;
        *buffer = (char *) realloc((void *) *buffer, *size);
        if (*buffer == NULL) {
            return (GET_INPUT_ALLOCATION_FAIL);
        }
    }
    return (GET_INPUT_CONTINUE);
}

static char *get_extended_input_init_buffer(
    size_t *len,
    size_t size,
    enum get_input_e *status,
    char character
)
{
    char *buffer = (char *) calloc(size, sizeof(char));

    if (buffer == NULL) {
        *status = GET_INPUT_ALLOCATION_FAIL;
        return (NULL);
    }
    if (character == -1) {
        *status = update_input(&buffer, len, &size);
    } else {
        buffer[(*len)++] = character;
    }
    return (buffer);
}

char *get_extended_input(
    struct sh *shell,
    enum get_input_e *status,
    char character
)
{
    enum get_input_e match = GET_INPUT_CONTINUE;
    size_t size = 64;
    size_t len = 0;
    char *buffer = get_extended_input_init_buffer(
        &len, size, status, character);

    if (*status != GET_INPUT_CONTINUE)
        return (NULL);
    while (match != GET_INPUT_NO_VALID_ACTION) {
        match = find_action_match(shell, buffer, len);
        if (match == GET_INPUT_ACTION_FOUND)
            return (NULL);
        if (match != GET_INPUT_NO_VALID_ACTION) {
            *status = update_input(&buffer, &len, &size);
            if (*status != GET_INPUT_CONTINUE) {
                return (buffer ? buffer : NULL);
            }
        }
    }
    return (buffer);
}
