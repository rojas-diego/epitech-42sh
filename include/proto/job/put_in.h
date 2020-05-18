/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** constants header file.
*/

#ifndef SH_PROTO_JOB_PUT_IN_H_
#define SH_PROTO_JOB_PUT_IN_H_

#include <stdbool.h>

#include "types/shell.h"
#include "types/job.h"

void job_put_in_foreground(
    struct sh *shell,
    struct job_s *job,
    bool does_continue
);

void job_put_in_background(struct job_s *job, bool does_continue);

#endif /* !SH_PROTO_JOB_PUT_IN_H_ */
