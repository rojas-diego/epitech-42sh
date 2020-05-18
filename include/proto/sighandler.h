/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** sig handler
*/

#ifndef SH_SIG_HANDLER_H_
#define SH_SIG_HANDLER_H_

#include <signal.h>

typedef void (*sighandler_t)(int);

void term_set_signal_handling(sighandler_t action);

#endif /* !SH_SIG_HANDLER_H_ */
