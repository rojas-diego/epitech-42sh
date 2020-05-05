/*
** EPITECH PROJECT, 2019
** parser_toolbox
** File description:
** ptb_characters
*/

#include <stdbool.h>

#include "parser_toolbox/range.h"

/*
** @DESCRIPTION
**   Returns true if the val parameter falls between min and max
**   Returns false otherwise.
*/
bool ptb_range(int val, int min, int max)
{
    return (val >= min && val <= max);
}
