/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:05:48 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/22 09:48:33 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

/* C LIBRARIES */

# include <unistd.h> // write / pause
# include <stdbool.h> // booleanos
# include <stdio.h> // printf
# include <stdlib.h> // EXIT_SUCESS ?? malloc free

# include <signal.h> // siginfo_t
// funciones SIGNALs -> getpid / SIGUSR1 / SIGUSR2 / signal / siginfo_t

#include <sys/types.h> // ??

/* OWN LIBRARIES */

/* FUNCIONES */

//void handler(int signum, siginfo_t *info, void *more_info);

void    Signal(int signum, void *handler, bool use_siginfo);



#endif