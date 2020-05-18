/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job process update status
*/

#ifndef SH_PROTO_JOB_PROCESS_UPDATE_STATUS_H_
#define SH_PROTO_JOB_PROCESS_UPDATE_STATUS_H_

#include <sys/types.h>

#include "types/job.h"

int job_process_update_status(struct job_s *first_job, pid_t pid, int status);

#endif /* !SH_PROTO_JOB_PROCESS_UPDATE_STATUS_H_ */
