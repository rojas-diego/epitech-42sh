/*
** EPITECH PROJECT, 2020
** find_binary
** File description:
** test double_array_size
*/

#include <stddef.h>

#include <criterion/criterion.h>

#include "double_array_size.h"

Test(double_array_size, simple_array_doubling)
{
    size_t size = 8;
    void *array = malloc(size);

    double_array_size(&array, &size);
    cr_assert_eq(size, 8 * 2);
    cr_assert_not_null(array);
    free(array);
}
