/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** continue job
*/

#ifndef SH_PROTO_JOB_CONTINUE_H_
#define SH_PROTO_JOB_CONTINUE_H_

#include <stdbool.h>

#include "types/shell.h"
#include "types/job.h"

void job_continue(struct sh *shell, struct job_s *job, bool foreground);

#endif /* !SH_PROTO_JOB_CONTINUE_H_ */
