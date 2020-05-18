/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job
*/

#ifndef SH_PROTO_JOB_UTILS_H_
#define SH_PROTO_JOB_UTILS_H_

#include "types/job.h"

struct job_s *job_find_from_pdig(struct job_s *first_job, pid_t pgid);
int job_is_stopped(struct job_s *job);
int job_is_completed(struct job_s *job);

#endif /* !SH_PROTO_JOB_UTILS_H_ */
