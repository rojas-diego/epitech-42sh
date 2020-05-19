/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** apply
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

#include "dnode/apply.h"
#include "dnode/insert.h"

static void display_data(void *data)
{
    char *str = (char *) data;

    write(STDOUT_FILENO, str, 9);
}

Test(dnode_apply, basic_func)
{
    struct dnode_s *list = NULL;

    dnode_insert_data(&list, "(int *)4");
    dnode_insert_data(&list, "(int *)6");
    dnode_insert_data(&list, "(int *)2");
    cr_redirect_stdout();
    dnode_apply(list, &display_data);
    cr_assert_stdout_eq_str("(int *)2(int *)6(int *)4");
}

Test(dnode_apply, null_func)
{
    struct dnode_s *list = NULL;

    dnode_insert_data(&list, (int *)4);
    dnode_insert_data(&list, (int *)6);
    dnode_insert_data(&list, (int *)2);
    dnode_apply(list, NULL);
}
