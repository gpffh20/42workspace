/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:32:14 by eushin            #+#    #+#             */
/*   Updated: 2023/06/23 16:13:20 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

void	find_format(const char *format)
{
	if (format == 'c')
		print_char();
	else if (format == 's')
		print_str();
	else if (format == 'p')
		print_ptr();
	else if (format == 'd')
		print_int();
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			find_format(format + 1);
		while (*format && *format != '%')
		{
			write(1, format, 1);
			format++;
		}
	}
	return 0;
}

int main()
{
	ft_printf("ME: 1234\n", 2);
	printf("ANS: 1234\n");

	return 0;
}
