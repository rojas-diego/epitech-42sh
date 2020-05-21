/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** tokens header file.
*/

#ifndef SH_CONSTANTS_TOKENS_H_
#define SH_CONSTANTS_TOKENS_H_

/**/
/* Includes */
/**/

/**/
/* Constants */
/**/





static const char *TOKENS[] = {
    "",         /* UNKNOW */
    "",         /* EOF */
    0,          /* WORD */
    "\n",       /* NEWLINE */
    0,          /* IO_NUMBER */
    "<",        /* LESS */
    ">",        /* GREAT */
    "|",        /* PIPE */
    ";",        /* SEMI */
    "&",        /* AMPERSAND */
    "&&",       /* AND_IF */
    "||",       /* OR_IF */
    ";;",       /* DSEMI */
    "<<",       /* DLESS */
    ">>",       /* DGREAT */
    "<&",       /* LESSAND */
    ">&",       /* GREATAND */
    "<>",       /* LESSGREAT */
    "<<-",      /* DLESSDASH */
    ">|",       /* CLOBBER */
    "{",        /* LBRACE */
    "}",        /* RBRACE */
    "(",        /* LBRACE */
    ")",        /* RBRACE */
    "!",        /* BANG */
    "break",    /* BREAK */
    "switch",   /* SWITCH */
    "case",     /* CASE */
    "breaksw",  /* BREAKSW */
    "default:", /* DEFAULT */
    "endsw",    /* ENDSW */
    "continue", /* CONTINUE */
    "foreach",  /* FOREACH */
    "end",      /* END */
    "goto",     /* GOTO */
    "if",       /* IF */
    "endif",    /* ENDIF */
    "else if",  /* ELSE IF */
    "else",     /* ELSE */
    "then",     /* THEN */
    "repeat",   /* REPEAT */
    "while"     /* WHILE */
};

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

#endif
