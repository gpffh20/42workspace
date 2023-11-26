#include "pipex.h"

int	error_handle(int errnum)
{
	if (errnum == 1)
		ft_printf("Number of Argument Error!\n");
	else if (errnum == 2)
		ft_printf("Pipe Error!: %s\n", strerror(errno));
	else if (errnum == 3)
		ft_printf("Fork Error!: %s\n", strerror((errno)));
	else if (errnum == 4)
		ft_printf("Open Error!: %s\n", strerror(errno));
	else if (errnum == 5)
		ft_printf("Dup Error!: %s\n", strerror(errno));
	exit(1);
}

char	**get_envpath(char **envp)
{
	int 	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			break ;
		i++;
	}
	return (ft_split(envp[i][5], ':');
}

char	*get_arg(char *cmd1, char **envp)
{
	char	**cmd;
	char	**arg;
	char 	**path;
	int 	i;

	i = 0;
	path = get_envpath(envp);
	cmd = ft_split(cmd1, ' ');
	char *cmd_path_tmp = ft_strjoin("/", cmd[0]);
	while (path[i])
	{
		char *cmd_path = ft_strjoin(path[i], cmd_path_tmp);
		int is_success = access(cmd_path, X_OK);
		if (is_success == 0)
		{
//			free (cmd_path_tmp);
			break ;
//			return (cmd_path);
		}
		close (is_success);
		free (cmd_path);
		i++;
	}
	arg = {
			cmd_path_tmp,

	};
}

void	exec_child(t_args *args, t_fds *fds, t_exec_args *exec_args)
{
	close(args->pipe[0]); // 파이프값을 읽을 일 없으니 바로 닫아줌
	if (dup2(fds->infile_fd, STDIN_FILENO) < 0)// infile_fd가 stdin fd를 복사 -> infile이 stdin을 가르키게 됨. 즉 stdin하면 infjle에 저장
		return (error_handle(5));
	if (dup2(args->pipe[1], STDOUT_FILENO) < 0)	// stdout하면 fd[1]에 저장
		return (error_handle(5));
	close(args->pipe[1]);
	close(fds->infile_fd);
	execve(exec_args->cmd1, exec_args->arg1, args->envp);
}

void	exec_parents(t_args *args, t_fds *fds, t_exec_args *exec_args)
{
	int status;

	close(args->pipe[1]);
	if (dup2(args->pipe[0], STDIN_FILENO) < 0)
		return (error_handle(5));
	if (dup2(fds->outfile_fd, STDOUT_FILENO) < 0)
		return (error_handle(5));
	close(args->pipe[0]);
	close(fds->outfile_fd);
	waitpid(args->pid, &status, WNOHANG);
	execve(exec_args->cmd2, exec_args->arg2, args->envp);
}

void	init_exec_args()
{

}

void	execute(t_args *args, t_fds *fds)
{
	t_exec_args exec_args;

	init_exec_args();
	if (pid == 0)
	{
		exec_child(args, fds, &exec_args);
	}
	else
	{
		exec_parents(args, fds, &exec_args);
	}
}

void	open_file(t_args *args, t_fds *fds)
{
	fds->infile_fd = open(args->av[1], O_RDONLY);
	fds->outfile_fd = open(args->av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fds->infile_fd < 0 || fds->outfile_fd < 0)
		return (error_handle(4));
}

void	init_args(t_args *args, char **av, char **envp)
{
	args->av = av;
	args->envp = envp;
}

int	main(int ac, char *av[], char *envp[])
{
	t_fds	fds;
	t_args args;

	if (ac != 5)
		return (error_handle(1));
	init_args(&args, av, envp);
	open_file(&args, &fds);
	if (pipe(args.pipe) < 0)
		return (error_handle(2));
	args.pid = fork();
	if (args.pid < 0)
		return (error_handle(3));
	execute(&args, &fds);
}