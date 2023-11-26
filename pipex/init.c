#include "pipex.h"

void	init_args(t_args *args, char **av, char **envp)
{
	args->av = av;
	args->envp = envp;
}

void	init_exec_args(t_exec_args *exec_args, t_args *args)
{
	exec_args->arg1 = ft_split(args->av[2], ' ');
	exec_args->arg2 = ft_split(args->av[3], ' ');
	exec_args->cmd1 = get_cmd(exec_args->arg1[0], args->envp);
	exec_args->cmd2 = get_cmd(exec_args->arg2[0], args->envp);
	if (exec_args->cmd1 == NULL || exec_args->cmd2 == NULL)
		return (error_handle(6));
	exec_args->arg1[0] = exec_args->cmd1;
	exec_args->arg2[0] = exec_args->cmd2;
}
