/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** create
*/

/* malloc */
#include <stdlib.h>

#include "dnode/create.h"

/*
** @Description
**   Create a new node with send data
*/
struct dnode_s *dnode_create(void *data)
{
    struct dnode_s *new = malloc(sizeof(struct dnode_s));

    if (!new) {
        return (NULL);
    }
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}
