/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:34:59 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/27 17:59:46 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

/* EXTERNAL LIBRARIES */

#include <unistd.h> // write pause usleep getpid 

#include <stdlib.h> // malloc free

# include <string.h> // ?
# include <sys/types.h> // ?
# include <sys/select.h> // ?

#include <stdio.h> // ?

/* OWN LIBRARIES */

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

//Compatibilidad POSIX no habilitada
/* Algunas funciones y estructuras, incluidas las relacionadas con señales, requieren habilitar un nivel de compatibilidad POSIX en el compilador. Esto es común cuando programas en sistemas que no usan POSIX completamente por defecto, como WSL. */
#define _POSIX_C_SOURCE 200809L

#include <signal.h> // signal sigaction siginfo_t sigemptyset

/* FUNCTIONS */

/** 
* @brief Funcion manejadora señales. Convierte una secuencia de bits recibidos
de las señales emitidas por el cliente en caracter (8 bits) a imprimir.
* @param signal int: señal recibida.
* @returns void-> . 
*/
void	receive_signals_and_confirm(int signum, siginfo_t *info, void *context);

/** 
* @brief Convierte un caracter en una secuencia de bits para emitir mediante 
señales 'SIGUSR1' y 'SIGUSR2' a un proceso con pid 'server_pid'.
* @param server_pid int: id proceso receptor.
* @param character char: caracter al que convertir en secuencia bits y enviar.
* @returns void-> . 
*/
void    send_signals(int server_pid, char character);

#endif