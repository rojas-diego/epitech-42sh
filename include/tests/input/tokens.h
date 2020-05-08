/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** tokens header file.
*/

#ifndef SH_TESTS_INPUT_TOKENS_H_
#define SH_TESTS_INPUT_TOKENS_H_

/**/
/* Includes */
/**/

/**/
/* Constants */
/**/

typedef struct w2conststring_s {
    char const *value1;
    char const *value2;
} w2conststring_t;

static const struct w2conststring_s TOKEN_NAMES[] = {
    {"Argument", "*"},
    {"Pipe", "|"},
    {"Separator", ";"},
    {"Inside Redirection", "<"},
    {"Inside Double Redirection", "<<"},
    {"Outside Redirection", ">"},
    {"Outside Double Redirection", ">>"},
    {"Open Paranth", "("},
    {"Closed Paranth", ")"},
    {"And Conditional", "&&"},
    {"Job Control", "&"},
    {"Or Conditional", "||"},
    {"Newline", "\n"},
    {"Double Separator", ";;"},
    {"Great And", ">&"},
    {"Less And", "<&"},
    {"Less Great", "<>"},
    {"Double Less Dash", "<<-"},
    {"Clobber", ">|"},
    {"If", "if"},
    {"Fi", "fi"},
    {"Then", "then"},
    {"Else", "else"},
    {"Elif", "elif"},
    {"Case", "case"},
    {"Esac", "esac"},
    {"For", "for"},
    {"Do", "do"},
    {"Done", "done"},
    {"Backticks", "`"},
    {"Undefined", "?"}
};

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

#endif
