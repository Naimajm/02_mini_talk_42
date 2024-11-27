/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:05:48 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/27 20:12:09 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* EXTERNAL LIBRARIES */

# include <unistd.h> // write / pause / usleep
# include <signal.h> // signal
# include <stdlib.h> // malloc free

//#include <sys/types.h> // pid_t
//#include <stdio.h> // printf

/* OWN LIBRARIES */

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

/* FUNCTIONS */

/** 
* @brief Funcionn manejadora señales. Convierte una secuencia de bits recibidos 
de las señales emitidas por el cliente en caracter (8 bits) a imprimir.
* @param signal int: señal recibida.
* @returns void-> . 
*/
void	receive_signals(int signum);

/** 
* @brief Convierte un caracter en una secuencia de bits para emitir mediante 
señales 'SIGUSR1' y 'SIGUSR2' a un proceso con pid 'server_pid'.
* @param server_pid int: id proceso receptor.
* @param character char: caracter al que convertir en secuencia bits y enviar.
* @returns void-> . 
*/
void	send_signals(int pid, char character);

void	print_bits(unsigned char octet);

#endif