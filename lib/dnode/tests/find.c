/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** find
*/

#include <criterion/criterion.h>

#include "dnode/find.h"
#include "dnode/insert.h"

static _Bool is_identic(void *data1, void *data2)
{
    return (data1 == data2);
}

Test(dnode_find, basic_test)
{
    struct dnode_s *list = NULL;
    struct dnode_s *node = NULL;

    dnode_insert_data(&list, "-h");
    dnode_insert_data(&list, "salut");
    node = dnode_find(list, list->data, &is_identic);
    cr_assert_str_eq(node->data, list->data);
}
