/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:35:59 by juagomez          #+#    #+#             */
/*   Updated: 2024/11/25 20:38:18 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	int	ft_putchar_bits(char character);

void	print_bits(unsigned char octet)
{
	int	operator;
	int displacement_number;

	operator = 128; // potencia de 2 elevado a 7
	displacement_number = 1; // numero desplazamiento de la representacion binaria del entero
	while (operator > 0)
	{
		// OPERADOR BIT A BIT 'bitwise' -> 'AND binario' par bits
		// https://es.wikipedia.org/wiki/Operador_a_nivel_de_bits
		// coincidencia entre para de bits -> 1 , si bit de los dos operandos es 1
		// se obtiene valor de cada bit por operando
		if (operator & octet)
			ft_putchar_bits('1');
		else
			ft_putchar_bits('0');

		//printf(" -> %i \n", operator);
		
		// OPERARDOR BIT A BIT DE DESPLAZAMIENTO '>>' '<<'	
		// desplazamiento 1 posicion equivale a dividir por 2 el numero
		// 128 -> 64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1 (8 posiciones)
		// 10000000 -> 01000000 -> 00100000 -> 00010000 -> 00001000 -> 00000100 -> 0000010 -> 0000001 ->
		operator = operator >> displacement_number;		
	}
}

static	int	ft_putchar_bits(char character)
{
	return  (write(1, &character, 1));
}