#include <stdio.h>

int main(void)
{
	char c;
	int i = 41; 

	c = getchar();
	while(i--)
	{
		printf("%c", c);
		c = getchar();
	}

	return 0;
}
