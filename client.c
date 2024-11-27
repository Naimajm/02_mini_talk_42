/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:49:40 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/27 20:31:34 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// ENTRADA TERMINAL <> .SERVER <PID> <MENSAJE>
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
		//ft_printf("server_pid (client)  -> %d \n", server_pid);
		//ft_printf("mensaje string-> %s \n", message);	

		// ciclo envio pack bits por cada caracter
		while (message[index] != '\0')
		{
			send_signals(server_pid, message[index]);
			index++;
		}
		send_signals(server_pid, '\n'); // envio separador		
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
	
	//ft_printf("character bits -> \n");
	//print_bits(character);
	//ft_printf("\n");
	
	bit_position = 0;
	while (bit_position < 8)
	{
		bit_value = (1 << bit_position);
		//ft_printf("bits_number -> %d \n", bits_position);		
		//print_bits(bit_value);
		//ft_printf("\n");

		if (character & bit_value) // coincide en ambos en esa posicion de bit
		{
			kill(server_pid, SIGUSR1); // bit 1
			//ft_printf("bit 1 -> SIGUSR1 \n");
		}
		else
		{
			kill(server_pid, SIGUSR2); // bit 0
			//ft_printf("bit 0 -> SIGUSR2 \n");
		}
		bit_position++;
		usleep(300);
	}
}
