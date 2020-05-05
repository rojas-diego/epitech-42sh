/*
** EPITECH PROJECT, 2019
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

void shell_struct_initialise(
    struct sh *this,
    __attribute__((unused)) int ac,
    __attribute__((unused)) char *const *av,
    __attribute__((unused)) char *const *ep
);
void shell_start(struct sh *shell);

#endif
