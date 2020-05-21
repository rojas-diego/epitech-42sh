/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** insert
*/

#include <criterion/criterion.h>

#include "dnode/create.h"
#include "dnode/insert.h"

Test(dnode_insert, basic_test)
{
    struct dnode_s *list = NULL;

    dnode_insert(&list, dnode_create("???"));
    dnode_insert(&list, dnode_create("ça va"));
    dnode_insert(&list, dnode_create("comment"));
    dnode_insert(&list, dnode_create("salut"));
    cr_assert_str_eq(list->data, "salut");
    cr_assert_str_eq(list->next->data, "comment");
    cr_assert_str_eq(list->next->next->data, "ça va");
    cr_assert_str_eq(list->next->next->next->data, "???");
    list = list->next->next->next;
    cr_assert_str_eq(list->prev->prev->prev->data, "salut");
    cr_assert_str_eq(list->prev->prev->data, "comment");
    cr_assert_str_eq(list->prev->data, "ça va");
    cr_assert_str_eq(list->data, "???");
    cr_assert_null(list->next);
    cr_assert_null(list->prev->prev->prev->prev);
}

Test(dnode_insert_data, basic_test)
{
    struct dnode_s *list = NULL;

    dnode_insert_data(&list, "???");
    dnode_insert_data(&list, "ça va");
    dnode_insert_data(&list, "comment");
    dnode_insert_data(&list, "salut");
    cr_assert_str_eq(list->data, "salut");
    cr_assert_str_eq(list->next->data, "comment");
    cr_assert_str_eq(list->next->next->data, "ça va");
    cr_assert_str_eq(list->next->next->next->data, "???");
    list = list->next->next->next;
    cr_assert_str_eq(list->prev->prev->prev->data, "salut");
    cr_assert_str_eq(list->prev->prev->data, "comment");
    cr_assert_str_eq(list->prev->data, "ça va");
    cr_assert_str_eq(list->data, "???");
    cr_assert_null(list->next);
    cr_assert_null(list->prev->prev->prev->prev);
}
