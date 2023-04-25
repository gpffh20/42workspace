/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:14:39 by eushin            #+#    #+#             */
/*   Updated: 2023/04/25 19:18:28 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		cnt;
	t_list	*tmp;

	tmp = lst;
	cnt = ft_lstsize(tmp);
	while (cnt != 1)
	{
		lst = lst->next;
		size--;
	}
	return (tmp);
}
