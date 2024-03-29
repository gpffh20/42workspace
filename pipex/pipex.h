/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:30:16 by eushin            #+#    #+#             */
/*   Updated: 2023/11/27 20:06:15 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./ft_printf/ft_printf.h"
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		pipe[2];
	char	**path;
	char	**envp;
	char	**arg1;
	char	**arg2;
}	t_pipex;

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	error_handle(int errnum);
int		execute(t_pipex *args, char **av);
void	init_args(t_pipex *args, char **av);
char	*get_cmd_path(char *cmd, char **path);
char	**get_path(char **envp);
void	ft_putstr_fd(char *s, int fd);

#endif
