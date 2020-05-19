/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** validator header file.
*/

#ifndef SH_CONSTANTS_VALIDATOR_H_
#define SH_CONSTANTS_VALIDATOR_H_

/**/
/* Includes */
/**/

#include "proto/token.h"

/**/
/* Constants */
/**/
/*
** @DESCRIPTION
**   Function pointer typedef used in TOK_VALIDATORS table.
*/
typedef unsigned int (*vafunc_f)(char const *string, char const *value);

/*
** @DESCRIPTION
**   This function assigns a handler function for each token type.
*/
static const vafunc_f TOK_VALIDATORS[] = {
    token_validate_token,
    token_validate_token,
    token_validate_word,
    token_validate_assignment_word,
    token_validate_name,
    token_validate_token,
    token_validate_io_number,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token,
    token_validate_token
};

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

#endif
