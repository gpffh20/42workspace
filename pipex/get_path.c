#include "pipex.h"

char	**get_path(char **envp)
{
	int 	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			break ;
		i++;
	}
	return (ft_split(&envp[i][5], ':'));
}