/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell header file.
*/

#ifndef SH_TYPES_SHELL_H_
#define SH_TYPES_SHELL_H_

/**/
/* Includes */
/**/

#include <stdio.h>
#include <stdbool.h>

#include "mynode.h"
#include "hasher/type.h"
#include "types/history.h"

#include "types/prompt.h"
#include "types/job.h"

/**/
/* Constants */
/**/

/**/
/* Structures / Typedef / Enums declarations */
/**/
/*
** @DESCRIPTION
**   Error wrapper.
*/
enum sh_error_e {
    ER_NONE,
    ER_MALLOC,
    ER_SYSCALL,
    ER_GRAMMAR
};

struct debug_mode_s {
    int depth;
};

/*
** @DESCRIPTION
**   Main shell structure.
** @MEMBERS
**   - active: the shell will run while active is true.
**   - rawinput: the input from the user fetched with getline.
**   - tokens: a linked list containing the parsed tokens for the rawinput.
**   - envp: the environement as an array of strings.
*/
typedef struct sh {
    bool                    debug_mode;
    bool                    active;
    char                    *rawinput;
    struct node_s           *tokens;
    pid_t                   pgid;
    char * const            *envp;
    struct prompt           prompt;
    int                     atty;
    int                     last_status;
    struct history_s        history;
    struct hasher_s         *builtin;
    struct hasher_s         *alias;
    struct hasher_s         *bindkey;
    struct hasher_s         *local_var;
    enum sh_error_e         error;
    struct job_s            *job;
    int                     fd;
    FILE                    *stream;
    struct expr_program_s   *expression;
    struct debug_mode_s     debug;
} sh_t;
/*
** Attribute:
**  active, pgid, atty, fd, debug_mode, error
** Cat:
**  history, builtin alias bindkey
** ???:
**  rawinput, prompt
** Exec:
**  job, tokens
*/

/**/
/* Function prototypes */
/**/

#endif
