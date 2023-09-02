#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("test.txt" ,O_RDONLY);
	int cnt = 10;
//	while (cnt--)
//	{
//		printf("%s", get_next_line(fd));
//	}
	printf("%s", get_next_line(fd));
}
