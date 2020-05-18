/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** constants header file.
*/

#ifndef SH_PROTO_JOB_PROCESS_LAUNCH_H_
#define SH_PROTO_JOB_PROCESS_LAUNCH_H_

#include <stdbool.h>

#include "types/shell.h"
#include "types/job.h"

void process_launch(
    struct sh *shell,
    struct process_s *process,
    int fds[IO_COUNT],
    bool foreground
);

#endif /* !SH_PROTO_JOB_PROCESS_LAUNCH_H_ */
