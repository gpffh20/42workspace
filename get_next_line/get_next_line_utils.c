/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:44:13 by eushin            #+#    #+#             */
/*   Updated: 2023/09/10 20:11:49 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strchr(char *s, char c)
{
	int		i;

	if (!(char *)s)
		return (-1);
	i = -1;
	while (s[++i] != c)
		if (s[i] == '\0')
			return (-1);
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (ft_strlen(s) < start)
		start = ft_strlen(s);
	if (start + len > ft_strlen(s))
		str = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new_str;
	char	*tmp;

	tmp = (char *)s1;
	new_str = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (tmp[++i])
		new_str[i] = tmp[i];
	new_str[i] = 0;
	return (new_str);
}
