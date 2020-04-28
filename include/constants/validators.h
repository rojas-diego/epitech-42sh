/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** validator header file.
*/

#ifndef SH_CONSTANTS_VALIDATOR_H_
#define SH_CONSTANTS_VALIDATOR_H_

/**/
/* Includes */
/**/

#include "types/input/validator.h"

/**/
/* Constants */
/**/

#define VALID_ALPHANUM validatorAlpha | validatorNum
#define TOK_ARG_MASK VALID_ALPHANUM | validatorQuotes

/*
** @DESCRIPTION
**   This table is meant to be accessed using the value of the token's enum.
**   For each token it assigns a validator structure to be provided to the
**   token_validate method.
**
** @MODEL
**   mask | valid | maxlength | minlength
*/
static const struct validator_s VALIDATORS[] = {
    {TOK_ARG_MASK, 0, 0, 0},
    {0, "|", 1, 1},
    {0, ";", 1, 1},
    {0, "<", 1, 1},
    {0, "<", 2, 2},
    {0, ">", 1, 1},
    {0, ">", 2, 2},
    {0, "(", 1, 1},
    {0, ")", 1, 1},
    {0, "&", 2, 2},
    {0, "|", 2, 2},
    {0, "&", 1, 1},
    {0, "\n", 1, 1}
};

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

#endif
