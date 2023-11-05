/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:58:12 by eushin            #+#    #+#             */
/*   Updated: 2023/11/01 23:58:13 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int arr[], int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	quick_sort(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

static void	indexing(int *arr, int *sort_arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (arr[i] == sort_arr[j])
			{
				arr[i] = j;
				i++;
				break ;
			}
			j++;
		}
	}
}

int	is_sorted(t_deque *a)
{
	t_node	*tmp;

	tmp = a->front;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);

}

void	set_stack(t_deque *stack, int *arr, int len)
{
	int	i;
	int	*sort_arr;

	sort_arr = ft_strdup(arr, len);
	quick_sort(sort_arr, 0, len - 1);
	indexing(arr, sort_arr, len);
	check_dup(sort_arr, len);
	i = 0;
	while (i < len)
	{
		push_back(stack, arr[i]);
		i++;
	}
	if (is_sorted(stack))
		exit(0);
}