/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:18:15 by eushin            #+#    #+#             */
/*   Updated: 2023/03/19 16:09:22 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*ft_strdup(int *s1, int len)
{
	int	i;
	int	*new_str;
	int	*tmp;

	tmp = s1;
	new_str = (int *)malloc(sizeof(int) * (len));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = tmp[i];
		i++;
	}
	return (new_str);
}
