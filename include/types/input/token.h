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
    tokUndefined,
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
    tokJobControl
} tokent_t;

/**/
/* Function prototypes */
/**/

#endif
