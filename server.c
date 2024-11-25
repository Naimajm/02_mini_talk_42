/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:49:30 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/25 12:33:31 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_signal_Handler(int signum)
{
	printf("Signal number is %d", signum);
	
}

int	main (int argc, char **argv)
{	
	int	pid_server;

	// VALIDACION ERRORES ARGUMENTOS 
	if (argc != 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	
	// OBTENER PID SERVIDOR
	pid_server = getpid();
	printf("PID servidor -> %i \n", pid_server);

	// WRAPPER FUNCTION para manejar señales 	
	//Signal(SIGUSR1, handler, true); // señal SIGUSR1 recibida -> bit 1
	//Signal(SIGUSR2, handler, true); // señal SIGUSR2 recibida -> bit 0

	// funcion signal -> sighandler_t signal(int signum, sighandler_t handler)
	signal(29, &my_signal_Handler);

	signal(SIGALRM, SIG_IGN); // ignorar señal cuando se recibe

	// PROCESO ESCUCHA CONTINUA
	while (1)
	{
		printf("esperando recibir señales \n");
		sleep(2);
		//pause();
	}
	return (0);
}

/** 
* @brief 
* @param signum int:  .
* @param info siginfo_t: Estructura de informacion asociada a una señal.
* @param more_info void *: .
* @returns void-> . 
*/
/* void handler(int signum, siginfo_t *info, void *more_info)
{
	(void)	more_info;

	write(STDOUT_FILENO, "hello", 5);
	
} */

/** 
* @brief Configura los manejadores de señales con informacion siginfo opcional
para SIGUSR1 y SIGUSR2. Lógica:
-Se inicializa una estructura sigaction.
-Se establece handle_sig como el manejador de señales.
-Se configuran las banderas SA_RESTART y SA_SIGINFO.
-Se llama a sigaction para registrar los manejadores de SIGUSR1 y SIGUSR2.
-Si sigaction falla, el programa termina con exit(EXIT_FAILURE).  
* @param signum int: Señal a manejar.
* @param handler void *: Función handler que especifica la acción a realizar.
* @param use_siginfo bool: Boleano para determinar si 'siginfo' es necesaria.
* @returns void-> . 
*/
/* void    Signal(int signum, void *handler, bool use_siginfo)
{
	struct sigaction	sig_action_estructur = {0};

	// COLOCAR FUNCION HANDLER DENTRO DE SIGACTION
	if (use_siginfo)
	{
		sig_action_estructur.sa_flags = SA_SIGINFO;
		sig_action_estructur.sa_sigaction = handler;
	}
	else
		sig_action_estructur.sa_handler = handler;

	// BLOQUEAR 'SIGUSR1' MIENTRAS SE ESTÁ PROCESANDO 'SIGUSR2' y viceversa
	// INICIALIZA SEÑALES DENTRO DEL ATRIBUTO 'MASK'
	sigemptyset(&sig_action_estructur.sa_mask); 
	// añadir señal bloqueada en ejecucion de funciopn handler
	sigaddset(&sig_action_estructur.sa_mask, SIGUSR1); 
	sigaddset(&sig_action_estructur.sa_mask, SIGUSR2);
	
    // VERIFIVCACION ERRORES activar funcion 'sigaction'
	if (sigaction(signum, &sig_action_estructur, NULL) < 0)  // return -1 error
	{
		perror("Sigaction failed");
		exit(1);
	}	
	else
		sig_action_estructur.sa_handler = handler;

	// BLOQUEAR 'SIGUSR1' MIENTRAS SE ESTÁ PROCESANDO 'SIGUSR2' y viceversa
	// INICIALIZA SEÑALES DENTRO DEL ATRIBUTO 'MASK'
	sigemptyset(&sig_action_estructur.sa_mask); 
	// añadir señal bloqueada en ejecucion de funciopn handler
	sigaddset(&sig_action_estructur.sa_mask, SIGUSR1); 
	sigaddset(&sig_action_estructur.sa_mask, SIGUSR2);
	
    // VERIFIVCACION ERRORES activar funcion 'sigaction'
	if (sigaction(signum, &sig_action_estructur, NULL) < 0)  // return -1 error
	{
		perror("Sigaction failed");
		exit(1);
	}

} */