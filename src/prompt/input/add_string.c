/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** prompt action add_char
*/

/* isprint */
#include <ctype.h>

#include "proto/prompt/input/add_char.h"
#include "proto/prompt/input/add_string.h"

void prompt_input_add_string(struct sh *shell, const char *str)
{
    for (size_t index = 0; str[index] != '\0'; ++index) {
        if (isprint(str[index])) {
            prompt_input_add_char(shell, str[index]);
        }
    }
}
