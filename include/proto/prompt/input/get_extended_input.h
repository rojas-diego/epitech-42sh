/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** sh input get_extended_input
*/

#ifndef SH_PROTO_INPUT_GET_EXTENDED_INPUT_H_
#define SH_PROTO_INPUT_GET_EXTENDED_INPUT_H_

#include "types/shell.h"
#include "types/prompt/input.h"

char *get_extended_input(
    struct sh *shell,
    enum get_input_e *status,
    char character
);

#endif /* !SH_PROTO_INPUT_GET_EXTENDED_INPUT_H_ */
