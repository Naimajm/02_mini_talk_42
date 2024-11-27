/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:31:36 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/27 20:43:38 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_signals_configuration(void);

int	main(int argc, char **argv)
{
	int	server_pid;

	(void)argv; // ignorar argumentos
			
	server_pid = getpid(); // OBTENER PID SERVIDOR
	
	// VALIDACION ERRORES ARGUMENTOS + PID SERVER 
	if (argc != 1 || !server_pid)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	// INTERFAZ CABECERA SERVER
	ft_printf("---------------------------------\n");
	ft_printf("-----  BONUS MINITALK SERVER ----\n");
	ft_printf("                                 \n");
	ft_printf("          Server PID -> %i       \n", server_pid);
	ft_printf("                                 \n");
	ft_printf("---------------------------------\n");
	ft_printf("---------------------------------\n");
	ft_printf("..........waiting for messages...\n");
	
	// Funcion manejadora señales. Recibe señal 'SIGUSR1' y 'SIGUSR2'
	ft_signals_configuration();
	while (1)
		pause(); // suspender el proceso hasta que se reciba una señal.
	return (0);
}

static void	ft_signals_configuration(void)
{
	struct sigaction	act;
	
	// Configura manejadores de señales SIGUSR1 y SIGUSR2 utilizando sigaction.
	act.sa_sigaction = receive_signals_and_confirm;
	sigemptyset(&act.sa_mask); // vaciar señales bloqueadas
	act.sa_flags = SA_SIGINFO;

	// Funcion manejadora señales. Recibe señal 'SIGUSR1' y 'SIGUSR2' 
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

static void	send_confirmation_signal(int signal, siginfo_t *info)
{
	int	client_pid;
	
	// ENVIO CONFIRMACION SEÑAL RECIBIDA	
	client_pid = info->si_pid;
	//printf("client_pid -> %d / signal %d \n", info->si_pid, signal);
	if (signal == SIGUSR1) // señal recibida es SIGUSR1
		// Envía la señal SIGUSR1 de vuelta al proceso cuyo ID es info->si_pid
		kill(client_pid, SIGUSR1); 
	else if (signal == SIGUSR2) // señal recibida es SIGUSR2
		kill(client_pid, SIGUSR2);
}

void	receive_signals_and_confirm(int signal, siginfo_t *info, void *context)
{
	static int	bit_position; // posicion actual del bit recibido		
	// Almacena el valor del carácter construido a partir de los bits recibido.
	static int	value;
	int			bit_value;

	(void)context; // ignorar argumento
	if (signal == SIGUSR1) // entra un bit 1
	{
		/* realiza una operación OR bit a bit (|) entre value y el valor 
		desplazado (<<). Establece el bit correspondiente en value sin alterar
		los otros bits. */
		bit_value = (1 << bit_position);
		// operación OR bit a bit (|) entre value y el bit recibido y desplazado
		value = value | bit_value;   
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
	// ENVIO CONFIRMACION SEÑAL RECIBIDA
	//printf("client_pid -> %d / signal %d \n", info->si_pid, signal);
	send_confirmation_signal(signal, info);
}
