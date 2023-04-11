/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:54:55 by eushin            #+#    #+#             */
/*   Updated: 2023/03/19 22:10:50 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_len(long long n, int len)
{
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}		

static char	*fill_str(long long n, int len)
{
	char	*str;
	int		flag;

	flag = len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
		flag--;
	}
	while (--len >= 0 && --flag >= 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;

	len = get_len(n, 1);
	return (fill_str(n, len));
}
