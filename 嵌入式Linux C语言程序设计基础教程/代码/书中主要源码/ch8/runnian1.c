#include <stdio.h>

int main()
{
	int i = 2000, n = 0;
	while(i < 2501)
	{
		if(i % 4 != 0)
		{
			i++;
			continue;
		}
		if(i % 100 != 0)// i % 4 == 0
		{
			n++;
			i++;
			continue;
		}
		if(i % 400 == 0)// i % 4 == 0 i % 100 == 0
			n++;
		i++;
	}
	printf("total: %d\n", n);

	return 0;
}
