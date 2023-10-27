/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:40:59 by eushin            #+#    #+#             */
/*   Updated: 2023/10/27 14:41:00 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef char	t_element;

typedef struct s_deque_node
{
	t_element			data;
	struct s_deque_node	*pre;
	struct s_deque_node	*next;
}	t_deque_node;

typedef struct s_deque
{
	int				size;
	t_deque_node	*rear;
	t_deque_node	*front;
}	t_deque;

t_deque	*create_deque(void);
void	push_front(t_deque *deque, t_element data);
void	push_back(t_deque *deque, t_element data);
void	pop_front(t_deque *deque);
void	pop_back(t_deque *deque);
void	sa(t_deque *a);
void	sb(t_deque *b);

#endif