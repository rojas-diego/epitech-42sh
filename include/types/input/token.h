/*
** EPITECH PROJECT, 2020
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
    TOK_ARGUMENT,
    TOK_PIPE,
    TOK_SEPARATOR,
    TOK_IN_REDIR,
    TOK_DIN_REDIR,
    TOK_OUT_REDIR,
    TOK_DOUT_REDIR,
    TOK_OPARANTH,
    TOK_CPARANTH,
    TOK_AND_CONDITIONAL,
    TOK_JOB_CONTROL,
    TOK_OR_CONDITIONAL,
    TOK_NEWLINE,
    TOK_DSEPARATOR,
    TOK_GREAT_AND,
    TOK_LESS_AND,
    TOK_LESS_GREAT,
    TOK_DLESS_DASH,
    TOK_CLOBBER,
    TOK_IF,
    TOK_FI,
    TOK_THEN,
    TOK_ELSE,
    TOK_ELIF,
    TOK_CASE,
    TOK_ESAC,
    TOK_FOR,
    TOK_DO,
    TOK_DONE,
    TOK_BACKTICKS,
    TOK_UNDEFINED,
    TOK_COUNT
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
