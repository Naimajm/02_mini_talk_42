/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:49:30 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/25 22:20:51 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main (int argc, char **argv)
{	
	int	pid_server;

	(void)argv;
	// VALIDACION ERRORES ARGUMENTOS 
	if (argc != 1)
	{
		ft_putstr_fd("Error\n",2);
		return (1);
	}	
	
	// TERMINAL SERVIDOR
	pid_server = getpid(); // OBTENER PID SERVIDOR

	ft_printf("---------------------------------\n");	
	ft_printf("--------  MINITALK SERVER -------\n");
	ft_printf("                                 \n");
	ft_printf("          Server PID -> %i       \n", pid_server);	
	ft_printf("                                 \n");	
	ft_printf("---------------------------------\n");
	ft_printf("---------------------------------\n");		
	ft_printf("..........waiting for messages...\n");	
	
	// PROCESO ESCUCHA CONTINUA
	while (1)
	{		
		// WRAPPER FUNCTION para manejar señales 
		// funcion signal -> sighandler_t signal(int signum, sighandler_t handler)	
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);	
		sleep(2);
		//pause();	
	}
	return (0);
}

void	ft_btoa(int signum)
{
	static 	int	bits_position; // numero de bits recibidos		
	// Almacena el valor del carácter construido a partir de los bits recibido
	static	int	value; 
	int bit_value;

	//printf("Signal number is %d \n", signum);		
	if (signum == SIGUSR1)  // entra un bit 1	
	{
		/* realiza una operación OR bit a bit (|=) entre value y el valor 
		desplazado (<<). Establece el bit correspondiente en value sin alterar
		los otros bits. */
		bit_value = (0X01 << bits_position); // 0x01 -> valor hexadecimal de 1 -> binario 00000001
		//print_bits(bit_value);
		//printf("\n");
		value = value | bit_value;   // operación OR bit a bit (|) entre value y el bit recibido y desplazado
		//print_bits(value);
		//printf("\n");
	}	
	print_bits(value);
	ft_printf("\n bits_number -> %d \n", bits_position);
	bits_position++; // se incrementa en cada llamada a la función.	
	
	if (bits_position == 8)
	{ 	 
		ft_printf("valor ascii -> %d \n", value); // valor ascii del caracter
		ft_printf("caracter -> %c \n", value);
		bits_position = 0; // reinicializacion de pack 8 bits
		value = 0;		
	}	
}