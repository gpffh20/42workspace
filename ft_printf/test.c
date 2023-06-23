#include <stdio.h>
#include <unistd.h>
int main()
{
	char a = '2';
	//printf("[%d] %d %d %c %c %%", 1, 2, 3, a, 'b');
	printf("%d\n", a);
	write(1, &a, 1);
}
