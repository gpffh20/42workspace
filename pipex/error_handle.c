#include "pipex.h"

void	error_handle(int errnum)
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
	else if (errnum == 6)
		ft_printf("Cannot found cmd path: %s\n", strerror(errno));
	exit(1);
}