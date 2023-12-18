/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:40:59 by eushin            #+#    #+#             */
/*   Updated: 2023/12/18 14:31:08 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_node
{
	int				data;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	int		size;
	t_node	*front;
	t_node	*back;
}	t_deque;

t_deque	*create_deque(void);
void	push_front(t_deque *deque, int data);
void	push_back(t_deque *deque, int data);
void	pop_front(t_deque *deque);
void	pop_back(t_deque *deque);
void	sa(t_deque *a, int flag);
void	sb(t_deque *b, int flag);
void	ss(t_deque *a, t_deque *b, int flag);
void	pa(t_deque *a, t_deque *b, int flag);
void	pb(t_deque *b, t_deque *a, int flag);
void	ra(t_deque *a, int flag);
void	rb(t_deque *b, int flag);
void	rr(t_deque *a, t_deque *b, int flag);
void	rra(t_deque *a, int flag);
void	rrb(t_deque *b, int flag);
void	rrr(t_deque *a, t_deque *b, int flag);
void	split_args(int ac, char *av[], t_deque *a);
int		print_error(void);
int		ft_atoi(const char *str);
int		*ft_strdup(int *s1, int len);
void	check_dup(int *arr, int limit);
void	under_five(t_deque *a, t_deque *b);
char	**ft_split(char const *s, char c);
int		is_sorted(t_deque *a);
void	short_sort(t_deque *a, t_deque *b);
void	free_deque(t_deque *stack);
void	free_str(char **str);
void	make_arr(t_deque *a, int *arr);
void	set_stack_bonus(t_deque *stack, int *arr, int len);
int		ft_strcmp(const char *s1, const char *s2);
void	do_op(t_deque *a, t_deque *b, char *op);
void	checker(t_deque *a, t_deque *b);
#endif
