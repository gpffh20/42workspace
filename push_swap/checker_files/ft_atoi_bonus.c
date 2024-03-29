/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:18:42 by eushin            #+#    #+#             */
/*   Updated: 2023/12/18 14:30:48 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	data_refine(char *str, int *is_minus)
{
	int	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		*is_minus = -1;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			is_minus;
	long long	num;

	num = 0;
	is_minus = 1;
	i = data_refine((char *)str, &is_minus);
	if (str[i] == '\0')
		exit(print_error());
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		else
			exit(print_error());
	}
	if (is_minus * num > INT_MAX || is_minus * num < INT_MIN)
		exit(print_error());
	return (is_minus * num);
}
