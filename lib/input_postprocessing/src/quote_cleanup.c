/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** quote_cleanup
*/

/* size_t */
#include <stddef.h>

/* */
#include "postprocess/quote_cleanup.h"

static void quote_cleanup_quote(
    char *str,
    size_t *index,
    size_t *mismatched_index,
    enum quote_cleaning_status_e *status
)
{
    if (*status == QUOTE_CLEANUP_CLOSED) {
        *status = str[(*index)++] == '"' ? QUOTE_CLEANUP_DOUBLE_QUOTE_OPENED
            : QUOTE_CLEANUP_SINGLE_QUOTE_OPENED;
        return;
    }
    if ((*status == QUOTE_CLEANUP_DOUBLE_QUOTE_OPENED && str[*index] == '\'')
    || (*status == QUOTE_CLEANUP_SINGLE_QUOTE_OPENED && str[*index] == '"')) {
        str[(*mismatched_index)++] = str[(*index)++];
        return;
    }
    ++(*index);
    *status = QUOTE_CLEANUP_CLOSED;
}

enum quote_cleaning_status_e ipp_quote_cleanup(char *str)
{
    enum quote_cleaning_status_e status = QUOTE_CLEANUP_CLOSED;
    size_t mismatched_index = 0;

    for (size_t index = 0; str[index] != '\0';) {
        if (str[index] == '\\') {
            str[mismatched_index++] = str[++index];
            ++index;
            continue;
        }
        if (str[index] == '\'' || str[index] == '"') {
            quote_cleanup_quote(str, &index, &mismatched_index, &status);
            continue;
        }
        str[mismatched_index++] = str[index++];
    }
    str[mismatched_index] = '\0';
    return (status);
}
