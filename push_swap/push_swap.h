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

# define INT_MIN -2147483648
# define INT_MAX 2147483647

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
void	ss(t_deque *a, t_deque *b);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *b, t_deque *a);
void	ra(t_deque *a);
void	rb(t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	rra(t_deque *a);
void	rrb(t_deque *b);
void	rrr(t_deque *a, t_deque *b);
int		ft_atoi(const char *str);
int		print_error(void);


#endif