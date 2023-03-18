/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:18:15 by eushin            #+#    #+#             */
/*   Updated: 2023/03/18 16:25:34 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*new_str;
	char	*tmp;

	size = 0;
	tmp = (char *)s1;
	while (tmp[size])
		size++;
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	size = 0;
	while (tmp[size])
	{
		new_str[size] = tmp[size];
		size++;
	}
	new_str[size] = 0;
	return (new_str);
}
