/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:20:44 by eushin            #+#    #+#             */
/*   Updated: 2023/06/27 16:22:26 by eushin           ###   ########.fr       */
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
		(*cnt) += write(1, &"0123456789ABCDEF"[nb % 16], 1);
	else
		(*cnt) += write(1, &"0123456789abcdef"[nb % 16], 1);
}

void	print_ptr(size_t var, int *cnt)
{
	(*cnt) += write(1, "0x", 2);
	print_hex(var, cnt, 0);
}
