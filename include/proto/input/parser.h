/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** executer header file.
*/

#ifndef SH_PROTO_INPUT_PARSER_H_
#define SH_PROTO_INPUT_PARSER_H_

/**/
/* Includes */
/**/

#include "types/shell.h"
#include "types/input/validator.h"

/**/
/* Constants */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

void input_parse(struct sh *shell);

unsigned int token_validate(char const *string, const struct validator_s va);

#endif
