/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** job
*/

#ifndef SH_TYPES_JOB_H_
#define SH_TYPES_JOB_H_

#include <termios.h>
#include <stdbool.h>
#include <stddef.h>

enum process_io_e
{
    IO_NOT = -1,
    IO_IN,
    IO_OUT,
    IO_ERR,
    IO_COUNT
};

struct process_s
{
    struct process_s *next;
    char **argv;
    size_t argc;
    size_t max_argc;
    pid_t pid;
    bool completed;
    bool stopped;
    char *subshell;
    int status;
};

struct job_s
{
    struct job_s *next;
    char *command;
    struct process_s *first_process;
    pid_t pgid;
    bool notified;
    struct termios tmodes;
    int io[IO_COUNT];
    bool foreground;
    int launch_id;
};

#endif /* !SH_TYPES_JOB_H_ */
