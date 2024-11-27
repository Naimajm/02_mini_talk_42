/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:31:36 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/27 21:13:03 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_signals_configuration(void);

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
	ft_printf("---------------------------------\n");
	ft_printf("-----  BONUS MINITALK SERVER ----\n");
	ft_printf("                                 \n");
	ft_printf("          Server PID -> %i       \n", server_pid);
	ft_printf("                                 \n");
	ft_printf("---------------------------------\n");
	ft_printf("---------------------------------\n");
	ft_printf("..........waiting for messages...\n");
	ft_signals_configuration();
	while (1)
		pause();
	return (0);
}

static void	ft_signals_configuration(void)
{
	struct sigaction	act;

	act.sa_sigaction = receive_signals_and_confirm;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

static void	send_confirmation_signal(int signal, siginfo_t *info)
{
	int	client_pid;

	client_pid = info->si_pid;
	if (signal == SIGUSR1)
		kill(client_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(client_pid, SIGUSR2);
}

void	receive_signals_and_confirm(int signal, siginfo_t *info, void *context)
{
	static int	bit_position;	
	static int	value;
	int			bit_value;

	(void)context;
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
	send_confirmation_signal(signal, info);
}
