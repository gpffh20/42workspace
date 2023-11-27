/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eushin <eushin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 04:29:30 by eushin            #+#    #+#             */
/*   Updated: 2023/11/27 04:29:31 by eushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void	exec_parents(t_pipex *args)
{
	close(args->pipe[1]);
	if (dup2(args->pipe[0], STDIN_FILENO) < 0)
		return (error_handle(5));
	close(args->pipe[0]);
}

static void	exec1_child(t_pipex *args, char *infile)
{
	int		infile_fd;
	char	*cmd_path;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd < 0)
		return (error_handle(4));
//	printf("infile: %d\n", infile_fd);
	close(args->pipe[0]);
	if (dup2(infile_fd, STDIN_FILENO) < 0)
		return (error_handle(5));
	close(infile_fd);
	if (dup2(args->pipe[1], STDOUT_FILENO) < 0)
		return (error_handle(5));
	close(args->pipe[1]);
	cmd_path = get_cmd_path(args->arg1[0], args->path);
//	ft_printf("cmd path: %s\n", cmd_path);
//	ft_putstr_fd(cmd_path, 2);
//	write(2, "haha\n", 5);
	if (execve(cmd_path, args->arg1, args->envp) == -1)
		return (error_handle(7));
}

static void	exec2_child(t_pipex *args, char *outfile)
{
	int		outfile_fd;
	char	*cmd_path;

	outfile_fd = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile_fd < 0)
		return (error_handle(4));
	if (dup2(outfile_fd, STDOUT_FILENO) < 0)
		return (error_handle(5));
	close(outfile_fd);
	cmd_path = get_cmd_path(args->arg2[0], args->path);
	if (execve(cmd_path, args->arg2, args->envp) == -1)
		return (error_handle(7));
}

int	execute(t_pipex *args, char **av)
{
	int		status;
	pid_t	pid;

//	init_args(args, av);
	if (pipe(args->pipe) < 0)
		error_handle(2);
//	printf("pipe: %d, %d\n", args->pipe[0], args->pipe[1]);
	pid = fork();
	if (pid < 0)
		error_handle(3);
	else if (pid == 0)
		exec1_child(args, av[1]);
	else
		exec_parents(args);
	pid = fork();
	if (pid < 0)
		error_handle(3);
	else if (pid == 0)
		exec2_child(args, av[4]);
	wait(&status);
	wait(&status);
	return (status);
}
