/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:31:19 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/27 20:08:17 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void    receive_confirmation_signals(int signal);

int main(int argc, char **argv)
{
    int     server_pid;
    char    *message;
    int     index;

    // Funcion manejadora señales. Recibe señal 'SIGUSR1' y 'SIGUSR2' 
    signal(SIGUSR1, receive_confirmation_signals);
    signal(SIGUSR2, receive_confirmation_signals);

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

/** 
* @brief Funcion manejadora señales. Recibe señal 'SIGUSR1' y 'SIGUSR2' 
e imprime mensaje recepcion .
* @param signal int: señal recibida.
* @returns void-> . 
*/
static void    receive_confirmation_signals(int signal)
{
    static  int bit_position;
    static  int value;
    int         bit_value;
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
		//ft_printf("valor ascii -> %d \n", value); // valor ascii del caracter        		
        if (value == '\n')
            ft_printf("<<< received message >>>\n");
        else if (value >= 32 && value <= 126)
            ft_printf("< char received '%c' >\n", value);
        else
            ft_printf("< char received >\n");
		bit_position = 0; // reinicializacion de pack 8 bits
		value = 0;	        
	}
}

void    send_signals(int server_pid, char character)
{
    int bit_position;
    int bit_value;

    bit_position = 0;
    while (bit_position < 8)
    {
        bit_value = (1 << bit_position);
        //ft_printf("bits_number -> %d \n", bits_position);		
		//print_bits(bit_value);
		//ft_printf("\n");
        if (character & bit_value) // coincide en ambos en esa posicion de bit
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        bit_position++;
        usleep(300);
    }    
}   