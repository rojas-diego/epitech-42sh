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
    tok_argument,
    tok_pipe,
    tok_separator,
    tok_in_redir,
    tok_din_redir,
    tok_out_redir,
    tok_dout_redir,
    tok_oparanth,
    tok_cparanth,
    tok_and_conditional,
    tok_or_conditional,
    tok_job_control,
    tok_newline,
    tok_dseparator,
    tok_great_and,
    tok_less_and,
    tok_less_great,
    tok_dless_dash,
    tok_clobber,
    tok_if,
    tok_fi,
    tok_then,
    tok_else,
    tok_elif,
    tok_case,
    tok_esac,
    tok_for,
    tok_do,
    tok_done,
    tok_undefined
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
