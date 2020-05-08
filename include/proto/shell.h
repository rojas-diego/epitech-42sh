/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell header file.
*/

#ifndef SH_PROTO_SHELL_H_
#define SH_PROTO_SHELL_H_

/**/
/* Includes */
/**/

#include "types/shell.h"

/**/
/* Constants */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/

/**/
/* Function prototypes */
/**/

int shell_struct_initialise(
    struct sh *this,
    int ac,
    char *const *av,
    char *const *ep
);
int shell_start(struct sh *shell);
void shell_destroy(struct sh *shell);

#endif
