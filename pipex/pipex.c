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
	exit(1);
}

int	main(int ac, char *av[], char *envp[])
{
	if (ac != 5)
		return (error_handle(1));

	int	infile_fd = open(av[1], O_RDONLY);
	int outfile_fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (infile_fd < 0 || outfile_fd < 0)
		return (error_handle(4));

	int fd[2];
	if (pipe(fd) < 0)
		return (error_handle(2));
	ft_printf("%s\n", p)

	pid_t pid;
	pid = fork();
	if (pid < 0)
		return (error_handle(3));
	else if (pid == 0)	//	자식 프로세스
	{
		close(fd[0]);
		dup2(infile_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(infile_fd);
		execve(cmd1, arg1, envp);
	}
	else	// 부모 프로세스
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(fd[0]);
		close(outfile_fd);

		int status;
		waitpid(pid, &status, WNOHANG);
		execve(cmd2, arg2, envp);

	}


}