/*
** EPITECH PROJECT, 2020
** parser_toolbox
** File description:
** ptb_strrpbrk
*/

#include <stddef.h>

#include "parser_toolbox/strrpbrk.h"

/*
** @DESCRIPTION
**   Returns last occurence of char in charset.
*/
char *ptb_strrpbrk(char *string, const char *charset)
{
    const char *accept;

    while (*string != '\0') {
        accept = charset;
        while (*accept != '\0') {
            if (*accept++ == *string) {
                return (string);
            }
        }
        ++string;
    }
    return (NULL);
}
