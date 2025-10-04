#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int sum, i;
	char c;

	srand(time(NULL));
	sum = 0;
	while (sum < 2645)
	{
		c = rand() % 94 + 33;
		sum += c;
		putchar(c);
	}
	putchar(2772 - sum);
	return (0);
}
