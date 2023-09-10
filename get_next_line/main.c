#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void	check(void)
{
	system("leaks --list -- a.out");
	//system("leaks a.out");
}

int main()
{
	atexit(check);
	int fd = open("empty.txt" ,O_RDONLY);
	printf("hello\n");
	int cnt = 8;
	char *line;
	while (cnt--)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	//printf("%s", get_next_line(fd));
}
