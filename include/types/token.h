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
typedef enum tokent_e
{
    TOK_NONE,
    TOK_EOF,
    TOK_WORD,
    TOK_ASSIGNMENT_WORD,
    TOK_NAME,
    TOK_NEWLINE,
    TOK_IONUMBER,
    TOK_LESS,
    TOK_GREAT,
    TOK_PIPE,
    TOK_SEMI,
    TOK_AMPERSAND,
    TOK_AND_IF,
    TOK_OR_IF,
    TOK_DSEMI,
    TOK_DLESS,
    TOK_DGREAT,
    TOK_LESSAND,
    TOK_GREATAND,
    TOK_LESSGREAT,
    TOK_DLESSDASH,
    TOK_CLOBBER,
    TOK_LBRACE,
    TOK_RBRACE,
    TOK_LPARANTH,
    TOK_RPARANTH,
    TOK_BANG,
    TOK_BREAK,
    TOK_SWITCH,
    TOK_CASE,
    TOK_BREAKSW,
    TOK_DEFAULT,
    TOK_ENDSW,
    TOK_CONTINUE,
    TOK_FOREACH,
    TOK_END,
    TOK_GOTO,
    TOK_IF,
    TOK_ENDIF,
    TOK_ELSE_IF,
    TOK_ELSE,
    TOK_THEN,
    TOK_REPEAT,
    TOK_WHILE,
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
