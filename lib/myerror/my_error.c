/*
** EPITECH PROJECT, 2019
** myerror
** File description:
** my_error
*/

#include "myerror.h"

/*
** @DESCRIPTION
**   Stores a program wide error variable to ensure processes ran errorlessly
**   Makes use of the my_error_mode_t enum (ERR_WRITE, ERR_READ).
** @USAGE
**   my_error(ERR_WRITE, 84); => Sets the error variable to 84.
**   my_error(ERR_READ, 0); => Returns the value of the error variable.
** @RETURN_VALUE
**   Returns an int.
**   'error' if ERR_READ is set.
**   0 if ERR_WRITE is set.
*/
int my_error(my_error_mode_t mode, int new_code)
{
    static int error;

    if (!error)
        error = 0;
    if (mode == ERR_WRITE)
        error = new_code;
    else
        return error;
    return 0;
}
