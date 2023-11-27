/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:30:16 by eushin            #+#    #+#             */
/*   Updated: 2023/11/27 04:30:17 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H


# include <stdio.h>




# include "./ft_printf/ft_printf.h"

# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		pipe[2];
	char	**path;	// envp path split
	char	**envp;	// envp from main(copy address)
	char	**arg1;	// cmd1 array(execve 2)
	char	**arg2;	// cmd2 array(execve 2)
}	t_pipex;

char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	error_handle(int errnum);
int		execute(t_pipex *args, char **av);
void	init_args(t_pipex *args, char **av);
char	*get_cmd_path(char *cmd, char **path);
char	**get_path(char **envp);
void	ft_putstr_fd(char *s, int fd);



#endif
