/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** find
*/

#include <criterion/criterion.h>

#include "dnode/find.h"
#include "dnode/insert.h"

static _Bool is_help(void *data)
{
    char *str = data;

    return (str[0] == '-' && str[1] == 'h' && !str[2]);
}

Test(dnode_find, basic_test)
{
    struct dnode_s *list = NULL;
    struct dnode_s *node = NULL;

    dnode_insert_data(&list, "-h");
    dnode_insert_data(&list, "salut");
    dnode_insert_data(&list, "wesh");
    node = dnode_find(list, &is_help);
    cr_assert_str_eq(node->data, "-h");
}
