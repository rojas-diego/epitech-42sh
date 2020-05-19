/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** create
*/

#include <criterion/criterion.h>

#include "dnode/create.h"

Test(dnode_create, basic_test)
{
    struct dnode_s *node = dnode_create("salut");

    cr_assert_not_null(node);
    cr_assert_null(node->prev);
    cr_assert_null(node->next);
    cr_assert_str_eq(node->data, "salut");
}
