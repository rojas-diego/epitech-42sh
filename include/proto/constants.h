/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** constants header file.
*/

#ifndef SH_CONSTANTS_CONSTANTS_H_
#define SH_CONSTANTS_CONSTANTS_H_

/**/
/* Prototypes */
/**/
/*
** @DESCRIPTION
**   Defines the character set to be used as whitespace when parsing.
*/
extern const char *WHITESPACE __attribute__((unused));

/*
** @DESCRIPTION
**   Defines the unwanted characters of a word token.
*/
extern const char *TOK_WORD_BLACKLIST __attribute__((unused));

/*
** @DESCRIPTION
**   Grammar error messages.
*/
extern const char *AST_EMPTY_IF __attribute__((unused));
extern const char *AST_EMPTY_ELSE __attribute__((unused));
extern const char *AST_EMPTY_ELSE_IF __attribute__((unused));
extern const char *AST_EMPTY_WHILE __attribute__((unused));
extern const char *AST_EMPTY_FOREACH __attribute__((unused));
extern const char *AST_EMPTY_REPEAT __attribute__((unused));

extern const char *AST_ELSE_IF_MISSING_THEN __attribute__((unused));
extern const char *AST_ELSE_MISSING_NEWLINE __attribute__((unused));
extern const char *AST_THEN_MISSING_NEWLINE __attribute__((unused));
extern const char *AST_INVALID_EXPRESSION __attribute__((unused));

extern const char *AST_NULL_COMMAND __attribute__((unused));

extern const char *AST_REPEAT_TOO_FEW_ARGS __attribute__((unused));

extern const char *AST_UNEXPECTED_TOKENS __attribute__((unused));

extern const char *AST_AMBIGUOUS_REDIRECTION __attribute__((unused));

const char *AST_MISSING_REDIRECT_NAME __attribute__((unused));

#endif
