/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** find
*/

#ifndef DNODE_FIND_H_
#define DNODE_FIND_H_

#include "dnode/type.h"

struct dnode_s *dnode_find_before(struct dnode_s *list, _Bool (*func)(void *));
struct dnode_s *dnode_find_after(struct dnode_s *list, _Bool (*func)(void *));
struct dnode_s *dnode_find(struct dnode_s *list, _Bool (*func)(void *));

#endif /* !DNODE_FIND_H_ */
