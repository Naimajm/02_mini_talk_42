/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:05:48 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/30 15:05:01 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

void	receive_signals(int signum);

void	send_signals(int pid, char character);

void	print_bits(unsigned char octet);

#endif