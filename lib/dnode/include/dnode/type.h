/*
** EPITECH PROJECT, 2020
** dnode
** File description:
** type
*/

#ifndef DNODE_TYPE_H_
#define DNODE_TYPE_H_

struct dnode_s {
    void *data;
    struct dnode_s *next;
    struct dnode_s *prev;
};

#endif /* !DNODE_TYPE_H_ */
