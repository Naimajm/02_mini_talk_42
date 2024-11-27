/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:49:30 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/27 21:12:01 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	server_pid;

	(void)argv;
	server_pid = getpid();
	if (argc != 1 || !server_pid)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	signal(SIGUSR1, receive_signals);
	signal(SIGUSR2, receive_signals);
	ft_printf("---------------------------------\n");
	ft_printf("--------  MINITALK SERVER -------\n");
	ft_printf("                                 \n");
	ft_printf("          Server PID -> %i       \n", server_pid);
	ft_printf("                                 \n");
	ft_printf("---------------------------------\n");
	ft_printf("---------------------------------\n");
	ft_printf("..........waiting for messages...\n");
	while (1)
		pause();
	return (0);
}

void	receive_signals(int signal)
{
	static int	bit_position;	
	static int	value;
	int			bit_value;

	if (signal == SIGUSR1)
	{
		bit_value = (1 << bit_position);
		value = value | bit_value;
	}
	else if (signal == SIGUSR2)
	{
		bit_value = (0 << bit_position);
		value = value | bit_value;
	}
	bit_position++;
	if (bit_position == 8)
	{
		ft_printf("%c", value);
		bit_position = 0;
		value = 0;
	}
}
