/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** insert
*/

#ifndef DNODE_INSERT_H_
#define DNODE_INSERT_H_

#include "dnode/type.h"

void dnode_insert(struct dnode_s **head, struct dnode_s *node);
void dnode_insert_data(struct dnode_s **head, void *data);

#endif /* !DNODE_INSERT_H_ */
