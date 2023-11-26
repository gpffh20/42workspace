#include "pipex.h"

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

void	execute(t_args *args, t_fds *fds)
{
	t_exec_args exec_args;

	init_exec_args(&exec_args, args);
	if (args->pid == 0)
	{
		exec_child(args, fds, &exec_args);
	}
	else
	{
		exec_parents(args, fds, &exec_args);
	}
}