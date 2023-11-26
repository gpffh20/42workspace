#include "pipex.h"

char	*get_cmd(char *cmd, char **envp)
{
	int i;
	int access_ok;
	char *cmd_path;
	char *cmd_tmp;
	char **env_path;

	i = 0;
	env_path = get_path(envp);
	cmd_path = ft_strjoin("/", cmd);
	while (env_path[i])
	{
		cmd_tmp = ft_strjoin(env_path[i], cmd_path);
		access_ok = access(cmd_tmp, X_OK);
		if (access_ok == 0)
		{
			free(cmd_path);
			return (cmd_tmp);
		}
		close(access_ok);
		free(cmd_tmp);
		i++;
	}
	free (cmd_path);
	return (NULL);
}