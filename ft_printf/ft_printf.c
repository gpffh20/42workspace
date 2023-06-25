/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:32:14 by eushin            #+#    #+#             */
/*   Updated: 2023/06/25 19:12:26 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


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
		(*cnt)++;
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
			else if (*format == 'p')
				print_ptr(va_arg(ap, size_t), &cnt);
			else if (*format == 'd' || *format == 'i')
				print_int(va_arg(ap, int), &cnt);
			else if (*format == 'u')
				print_unsignedint(va_arg(ap, unsigned int), &cnt);
			else if (*format == 'x' || *format == 'X')
				print_hex(va_arg(ap, unsigned int), &cnt, *format);
			else if (*format == '%')
			{
				write(1, "%", 1);
				cnt++;
			}
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
