/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:07:33 by eushin            #+#    #+#             */
/*   Updated: 2023/12/18 14:31:08 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	split_args(int ac, char *av[], t_deque *a)
{
	int		i;
	int		j;
	char	**tmp;

	i = 1;
	while (i < ac)
	{
		j = 0;
		tmp = ft_split(av[i], 32);
		while (tmp[j])
		{
			push_back(a, ft_atoi(tmp[j]));
			j++;
		}
		free_str(tmp);
		i++;
	}
}
