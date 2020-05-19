/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** goto
*/

#include <criterion/criterion.h>

#include "dnode/goto.h"
#include "dnode/insert.h"

Test(dnode_goto, basic_test)
{
    struct dnode_s *list = NULL;

    dnode_insert_data(&list, "salut");
    dnode_insert_data(&list, "comment");
    dnode_insert_data(&list, "ça va ?");
    list = dnode_goto_end(list);
    cr_assert_str_eq(list->data, "salut");
    cr_assert_str_eq(list->prev->data, "comment");
    cr_assert_str_eq(list->prev->prev->data, "ça va ?");
    cr_assert_null(list->prev->prev->prev);
}
