/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** apply
*/

#ifndef DNODE_APPLY_H_
#define DNODE_APPLY_H_

#include "dnode/type.h"

void dnode_apply(struct dnode_s *list, void (*func)(void *));

#endif /* !DNODE_APPLY_H_ */
