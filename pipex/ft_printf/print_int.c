/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:19:53 by eushin            #+#    #+#             */
/*   Updated: 2023/06/26 17:20:09 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_unsignedint(unsigned int nb, int *cnt)
{
	if (nb / 10 > 0)
	{
		print_unsignedint(nb / 10, cnt);
	}
	(*cnt) += write(1, &"0123456789"[nb % 10], 1);
}

void	print_int(int nb, int *cnt)
{
	if (nb == -2147483648)
	{
		(*cnt) += write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		(*cnt) += write(1, "-", 1);
	}
	if (nb / 10 > 0)
	{
		print_int(nb / 10, cnt);
	}
	(*cnt) += write(1, &"0123456789"[nb % 10], 1);
}
