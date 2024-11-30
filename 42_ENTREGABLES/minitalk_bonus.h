/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:34:59 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/30 15:05:00 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h> 
# include <stdlib.h> 

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

# define _POSIX_C_SOURCE 200809L

# include <signal.h>

void	receive_signals_and_confirm(int signum, siginfo_t *info, void *context);
void	send_signals(int server_pid, char character);

#endif