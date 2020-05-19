/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** free
*/

#include <stdlib.h>
#include <criterion/criterion.h>

#include "dnode/insert.h"
#include "dnode/free.h"

Test(dnode_free, basic_test)
{
    struct dnode_s *list = NULL;

    dnode_insert_data(&list, "salut");
    dnode_insert_data(&list, "salut");
    dnode_insert_data(&list, "salut");
    dnode_free(&list, NULL);
    cr_assert_null(list);
}
