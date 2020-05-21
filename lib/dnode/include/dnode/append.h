/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** append
*/

#ifndef DNODE_APPEND_H_
#define DNODE_APPEND_H_

#include "dnode/type.h"

void dnode_append(struct dnode_s **head, struct dnode_s *node);
void dnode_append_data(struct dnode_s **head, void *data);

#endif /* !DNODE_APPEND_H_ */
