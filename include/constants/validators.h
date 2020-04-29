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

#define VALID_ALPHANUM valiAlpha | valiNum
#define TOK_ARG_MASK VALID_ALPHANUM | valiQuotes | valiInvalid
#define TOK_RESERVED valiMatch | valiLower

/*
** @DESCRIPTION
**   This table is meant to be accessed using the value of the token's enum.
**   For each token it assigns a validator structure to be provided to the
**   token_validate method.
**
** @MODEL
**   mask | valid | maxlength | minlength*/
static const struct validator_s VALIDATORS[] = {
    {TOK_ARG_MASK, "><|;&()!", 0, 0}, // TokArgument
    {0, "|", 1, 1},                   // tokPipe
    {0, ";", 1, 1},                   // tokSeparator
    {0, "<", 1, 1},                   // tokInRedir
    {0, "<", 2, 2},                   // tokDInRedir
    {0, ">", 1, 1},                   // tokOutRedir
    {0, ">", 2, 2},                   // tokDOutRedir
    {0, "(", 1, 1},                   // tokOParanth
    {0, ")", 1, 1},                   // tokCParanth
    {0, "&", 2, 2},                   // tokAndConditional
    {0, "|", 2, 2},                   // tokOrConditional
    {0, "&", 1, 1},                   // tokJobControl
    {valiMatch, "\n", 0, 0},          // tokNewline
    {0, ";", 2, 2},                   // tokDSeparator
    {valiMatch, ">&", 1, 1},          // tokGreatAnd
    {valiMatch, "<&", 1, 1},          // tokLessAnd
    {valiMatch, "<>", 1, 1},          // tokLessGreat
    {valiMatch, "<<-", 1, 1},         // tokDLessDash
    {valiMatch, ">|", 1, 1},          // tokClobber
    {TOK_RESERVED, "if", 0, 0},       // tokIf
    {TOK_RESERVED, "fi", 0, 0},       // tokFi
    {TOK_RESERVED, "then", 0, 0},     // tokThen
    {TOK_RESERVED, "else", 0, 0},     // tokElse
    {TOK_RESERVED, "elif", 0, 0},     // tokElif
    {TOK_RESERVED, "case", 0, 0},     // tokCase
    {TOK_RESERVED, "esac", 0, 0},     // tokEsac
    {TOK_RESERVED, "for", 0, 0},      // tokFor
    {TOK_RESERVED, "do", 0, 0},       // tokDo
    {TOK_RESERVED, "done", 0, 0},     // tokDone
    {valiMatch, "", 0, 0},                   // tokUndefined
};

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

#endif
