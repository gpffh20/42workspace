/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:32:14 by eushin            #+#    #+#             */
/*   Updated: 2023/06/24 21:22:32 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void	print_str(char *var, int *cnt)
{
	write(1, var, strlen(var));
	(*cnt) += strlen(var);
}

void	print_char(int var, int *cnt)
{
	write(1, &var, 1);
	(*cnt)++;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	cnt;

	cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				print_char(va_arg(ap, int), &cnt);
			else if (*format == 's')
				print_str(va_arg(ap, char *), &cnt);
//			else if (*format == 'p')
//				print_ptr();
//			else if (*format == 'd' || *format == 'i')
//				print_int();
//			else if (*format == 'u')
//				print_unsignedint();
//			else if (*format == 'x' || *format == 'X')
//				print_hex();
		}
		else
		{
			write(1, format, 1);
			cnt++;
		}
		format++;
	}
	return (cnt);
}

int main()
{
	printf("MY P) %d\n", ft_printf("ME: %s\n", "abc"));
	printf("ANS P) %d\n", printf("ANS: %s\n", "abc"));

	return 0;
}
