/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:30:03 by eushin            #+#    #+#             */
/*   Updated: 2023/04/25 15:39:09 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*src;
	char			*dst;
	unsigned int	size;

	src = (char *)s;
	size = ft_strlen(src);
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (0);
	i = 0;
	while (i < size)
	{
		dst[i] = f(i, src[i]);
		i++;
	}
	dst[i] = 0;
	return (dst);
}
