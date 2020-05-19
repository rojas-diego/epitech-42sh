/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** free
*/

#ifndef DNODE_FREE_H_
#define DNODE_FREE_H_

#include "dnode/type.h"

void dnode_free(struct dnode_s **head, void (*func)(void *));

#endif /* !DNODE_FREE_H_ */
