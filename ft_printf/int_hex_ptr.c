/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_hex_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:14:21 by eushin            #+#    #+#             */
/*   Updated: 2023/06/25 21:19:16 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_hex(size_t nb, int *cnt, char format)
{
	if (nb / 16 > 0)
	{
		print_hex(nb / 16, cnt, format);
	}
	if (format == 'X')
		write(1, &"0123456789ABCDEF"[nb % 16], 1);
	else
		write(1, &"0123456789abcdef"[nb % 16], 1);
	(*cnt)++;
}

void	print_ptr(size_t var, int *cnt)
{
	write(1, "0x", 2);
	(*cnt) += 2;
	print_hex(var, cnt, 0);
}

void	print_unsignedint(unsigned int nb, int *cnt)
{
	if (nb / 10 > 0)
	{
		print_unsignedint(nb / 10, cnt);
	}
	write(1, &"0123456789"[nb % 10], 1);
	(*cnt)++;
}

void	print_int(int nb, int *cnt)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*cnt) += 11;
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		(*cnt)++;
	}
	if (nb / 10 > 0)
	{
		print_int(nb / 10, cnt);
	}
	write(1, &"0123456789"[nb % 10], 1);
	(*cnt)++;
}
