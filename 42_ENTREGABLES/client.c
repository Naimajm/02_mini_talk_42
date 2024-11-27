/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:49:40 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/27 21:13:25 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;
	int		index;

	index = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		message = argv[2];
		while (message[index] != '\0')
		{
			send_signals(server_pid, message[index]);
			index++;
		}
		send_signals(server_pid, '\n');
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

void	send_signals(int server_pid, char character)
{
	int	bit_position;	
	int	bit_value;

	bit_position = 0;
	while (bit_position < 8)
	{
		bit_value = (1 << bit_position);
		if (character & bit_value)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit_position++;
		usleep(300);
	}
}
