/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:14:39 by eushin            #+#    #+#             */
/*   Updated: 2023/04/27 18:13:17 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		cnt;
	t_list	*tmp;

	if (lst == NULL)
		return (0);
	tmp = lst;
	cnt = ft_lstsize(tmp);
	while (cnt != 1)
	{
		tmp = tmp->next;
		cnt--;
	}
	return (tmp);
}
