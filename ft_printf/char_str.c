/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:13:24 by eushin            #+#    #+#             */
/*   Updated: 2023/06/25 21:03:42 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_str(char *var, int *cnt)
{
	if (var == NULL)
	{
		write(1, "(null)", 6);
		(*cnt) += 6;
		return ;
	}
	write(1, var, ft_strlen(var));
	(*cnt) += ft_strlen(var);
}

void	print_char(int var, int *cnt)
{
	write(1, &var, 1);
	(*cnt)++;
}
