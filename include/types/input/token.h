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
**  Defines all of the shell tokens.
*/
typedef enum tokent_e {
    tokArgument,
    tokPipe,
    tokSeparator,
    tokInRedir,
    tokDInRedir,
    tokOutRedir,
    tokDOutRedir,
    tokOParanth,
    tokCParanth,
    tokAndConditional,
    tokOrConditional,
    tokJobControl,
    tokNewline,
    tokDSeparator,
    tokGreatAnd,
    tokLessAnd,
    tokLessGreat,
    tokDLessDash,
    tokClobber,
    tokIf,
    tokFi,
    tokThen,
    tokElse,
    tokElif,
    tokCase,
    tokEsac,
    tokFor,
    tokDo,
    tokDone,
    tokUndefined
} tokent_t;

/*
** @DESCRIPTION
**   Defines the structure for a token once parsed.
** @MEMBERS
**   - type: The type of token.
**   - start: the beginning of the token in the sh.rawinput string.
**   - start: the end of the token in the sh.rawinput string.
*/
typedef struct token_s {
    tokent_t type;
    unsigned int start;
    unsigned int end;
} token_t;

/**/
/* Function prototypes */
/**/

#endif
