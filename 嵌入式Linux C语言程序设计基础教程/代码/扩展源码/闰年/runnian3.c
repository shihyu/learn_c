#include <stdio.h>

int main()
{
	int i = 2000, n = 0;
	while(i < 2501)
	{
//		if((i % 4 == 0 && i % 100 != 0)
//			||(i % 100 == 0 && i % 400 == 0))
		if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0) )
		{
			printf("%d is a leap year\n", i);
			n++;
		}
		else
		{
			printf("%d is not a leap year\n", i);
		}

		i++;
	}
	printf("total: %d\n", n);



	return 0;
}
