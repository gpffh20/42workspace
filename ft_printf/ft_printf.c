/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:32:14 by eushin            #+#    #+#             */
/*   Updated: 2023/06/26 11:50:46 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	find_format(va_list ap, int *cnt, char format)
{
	if (format == 'c')
		print_char(va_arg(ap, int), cnt);
	else if (format == 's')
		print_str(va_arg(ap, char *), cnt);
	else if (format == 'p')
		print_ptr(va_arg(ap, size_t), cnt);
	else if (format == 'd' || format == 'i')
		print_int(va_arg(ap, int), cnt);
	else if (format == 'u')
		print_unsignedint(va_arg(ap, unsigned int), cnt);
	else if (format == 'x' || format == 'X')
		print_hex(va_arg(ap, unsigned int), cnt, format);
	else if (format == '%')
		(*cnt) += write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			find_format(ap, &cnt, *format);
		}
		else
			cnt += write(1, format, 1);
		format++;
	}
	return (cnt);
}
