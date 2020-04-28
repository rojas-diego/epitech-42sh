/*
** EPITECH PROJECT, 2019
** myptb
** File description:
** ptb_characters
*/

#include <stdbool.h>

/*
** @DESCRIPTION
**   Returns true if the val parameter falls between min and max
**   Returns false otherwise.
*/
bool ptb_range(int val, int min, int max)
{
    return (val > min && val < max);
}

/*
** @DESCRIPTION
**   Returns true if the c is contained in the values string.
**   Returns false otherwise.
*/
bool ptb_includes(const char c, const char *restrict values)
{
    for (unsigned int i = 0; values[i]; i++)
        if (c == values[i])
            return true;
    return false;
}
