/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:49:30 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/27 20:29:18 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	server_pid;

	(void)argv;
	// TERMINAL SERVIDOR
	server_pid = getpid(); // OBTENER PID SERVIDOR

	// VALIDACION ERRORES ARGUMENTOS + PID SERVER 
	if (argc != 1 || !server_pid)
	{
		ft_putstr_fd("Error\n",2);
		return(1);
	}	
	// funcion signal -> sighandler_t signal(int signum, sighandler_t handler)	
	signal(SIGUSR1, receive_signals);
	signal(SIGUSR2, receive_signals);

	// INTERFAZ CABECERA SERVER
	ft_printf("---------------------------------\n");
	ft_printf("--------  MINITALK SERVER -------\n");
	ft_printf("                                 \n");
	ft_printf("          Server PID -> %i       \n", server_pid);
	ft_printf("                                 \n");
	ft_printf("---------------------------------\n");
	ft_printf("---------------------------------\n");
	ft_printf("..........waiting for messages...\n");
	
	// PROCESO ESCUCHA CONTINUA
	while (1)
		pause(); // suspender el proceso hasta que se reciba una señal.
	return (0);
}

void	receive_signals(int signal)
{
	static int	bit_position; // posicion actual del bit recibido		
	// Almacena el valor del carácter construido a partir de los bits recibido
	// cuando sea 1 byte, se convvertira en el codigo ASCII del caracter
	static int	value;
	int			bit_value;
	
	//printf("Signal number is %d \n", signum);
	if (signal == SIGUSR1) // entra un bit 1
	{
		/* realiza una operación OR bit a bit (|) entre value y el valor 
		desplazado (<<). Establece el bit correspondiente en value sin alterar
		los otros bits. */
		bit_value = (1 << bit_position); // (1) -> binario 00000001
		//print_bits(bit_value);
		//printf("\n");
		
		// operación OR bit a bit (|) entre value y el bit recibido y desplazado
		value = value | bit_value;
		//print_bits(value);
		//printf("\n");
	}
	else if (signal == SIGUSR2)
	{
		bit_value = (0 << bit_position);
		value = value | bit_value;
	}
	//print_bits(value);
	//ft_printf("\n bit_position -> %d \n", bits_position);
	bit_position++; // se incrementa en cada llamada a la función.
	
	if (bit_position == 8)
	{
		//ft_printf("valor ascii -> %d \n", value); // valor ascii del caracter
		ft_printf("%c", value);
		bit_position = 0; // reinicializacion de pack 8 bits
		value = 0;
	}
}
