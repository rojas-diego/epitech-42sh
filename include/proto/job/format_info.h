/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job
*/

#ifndef SH_PROTO_JOB_INFO_H_
#define SH_PROTO_JOB_INFO_H_

#include "types/job.h"

void job_format_info_launch_background(struct job_s *job);
void job_format_info(struct job_s *job, const char *status, _Bool dumped);

#endif /* !SH_PROTO_JOB_INFO_H_ */
