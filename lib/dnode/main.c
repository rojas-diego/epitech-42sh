/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** main
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "dnode.h"

static void display_data(void *data)
{
    write(1, (char *)data, 9);
}

int main(void)
{
    struct dnode_s *list = NULL;

    dnode_insert_data(&list, "(int *)4");
    dnode_insert_data(&list, "(int *)6");
    dnode_insert_data(&list, "(int *)2");
    dnode_apply(list, &display_data);
    return (0);
}
