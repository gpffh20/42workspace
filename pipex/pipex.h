#ifndef PIPEX_H
# define PIPEX_H

# include "./ft_printf/ft_printf.h"

# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


typedef struct s_fds
{
	int	infile_fd;
	int	outfile_fd;
}	t_fds;

typedef struct s_args
{
	char	**av;
	char	**envp;
	pid_t	pid;
	int		pipe[2];
}	t_args;

typedef struct s_exec_args
{
	char	*cmd1;
	char	*cmd2;
	char	**arg1;
	char	**arg2;
}	t_exec_args;

char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);



#endif
