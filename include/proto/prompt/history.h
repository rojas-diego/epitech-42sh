/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** history
*/

#ifndef SH_PROTO_HISTORY_H_
#define SH_PROTO_HISTORY_H_

#include "types/history.h"

void history_insert(struct history_s *history, char const *line);
void history_destroy(struct history_s *history);
_Bool history_init(struct history_s *history);

#endif /* !SH_PROTO_HISTORY_H_ */
