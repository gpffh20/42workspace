/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:19:23 by eushin            #+#    #+#             */
/*   Updated: 2023/06/26 17:19:26 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_str(char *var, int *cnt)
{
	if (var == NULL)
	{
		(*cnt) += write(1, "(null)", 6);
		return ;
	}
	(*cnt) += write(1, var, ft_strlen(var));
}
