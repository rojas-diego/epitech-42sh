/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** shell header file.
*/

#ifndef SH_TYPES_SHELL_H_
#define SH_TYPES_SHELL_H_

/**/
/* Includes */
/**/

#include "stdbool.h"

/**/
/* Constants */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/

typedef struct sh {
    bool        active;
    char        *rawinput;
    char *const *envp;
} sh_t;

/**/
/* Function prototypes */
/**/

#endif
