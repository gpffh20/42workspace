/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:38:23 by eushin            #+#    #+#             */
/*   Updated: 2023/04/28 18:44:19 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static int	count_word(char *tmp, char c)
{
	int	i;
	int	word_cnt;

	i = 0;
	word_cnt = 0;
	while (tmp[i])
	{
		while (tmp[i] && tmp[i] == c)
			i++;
		if (tmp[i] && tmp[i] != c)
			word_cnt++;
		while (tmp[i] && tmp[i] != c)
			i++;
	}
	return (word_cnt);
}

static char	**ft_free(char **ret, int i)
{
	while (i)
		free(ret[--i]);
	free(ret);
	return (NULL);
}

static char	**ft_malloc(t_fdf *split_data, char **board, char *tmp, char c)
{
	int	i;
	int	len;
	int	idx;

	idx = 0;
	i = 0;
	while (i < split_data->row_cnt)
	{
		len = 0;
		while (tmp[idx] && tmp[idx] == c)
			idx++;
		while (tmp[idx + len] && tmp[idx + len] != c)
			len++;
		board[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!board[i])
			return (ft_free(board, i));
		board[i][len] = 0;
		idx += len;
		i++;
	}
	return (board);
}

static char	**fill_string(char **board, char *tmp, char c, int word_cnt)
{
	int	i;
	int	j;
	int	idx;

	idx = 0;
	i = 0;
	while (i < word_cnt)
	{
		j = 0;
		while (tmp[idx] && tmp[idx] == c)
			idx++;
		while (tmp[idx] && tmp[idx] != c)
		{
			board[i][j] = tmp[idx];
			idx++;
			j++;
		}
		i++;
	}
	return (board);
}

char	**ft_split(char const *s, char c, t_fdf *split_data)
{
	char	**board;
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = (char *)s;
	split_data->row_cnt = count_word(tmp, c);
	board = (char **)malloc(sizeof(char *) * (split_data->row_cnt + 1));
	if (!board)
		return (NULL);
	board[split_data->row_cnt] = 0;
	board = ft_malloc(split_data, board, tmp, c);
	if (!board)
		return (ft_free(board, 0));
	board = fill_string(board, tmp, c, split_data->row_cnt);
	free(tmp);
	return (board);
}
