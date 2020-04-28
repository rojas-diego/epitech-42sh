/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** token header file.
*/

#ifndef SH_TYPES_TOKEN_H_
#define SH_TYPES_TOKEN_H_

/**/
/* Includes */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/
/*
** @DESCRIPTION
**  Describes the type of shell token.
*/
typedef enum tokent_e {
    tokArgument,
    tokPipe,
    tokSeparator,
    tokInRedir,
    tokDoubleInRedir,
    tokOutRedir,
    tokDoubleOutRedir,
    tokOpenParanth,
    tokClosedParanth,
    tokAndConditional,
    tokOrConditional,
    tokJobControl,
    tokNewline
} tokent_t;

typedef struct token_s {
    tokent_t type;
    unsigned int start;
    unsigned int end;
} token_t;

/**/
/* Function prototypes */
/**/

#endif
