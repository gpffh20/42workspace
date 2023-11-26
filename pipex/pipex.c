#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	t_fds	fds;
	t_args args;

	if (ac != 5)
		error_handle(1);
	init_args(&args, av, envp);
	open_file(&args, &fds);
	if (pipe(args.pipe) < 0)
		error_handle(2);
	args.pid = fork();
	if (args.pid < 0)
		error_handle(3);
	execute(&args, &fds);
}