#include <stdio.h>

int main()
{
	int n, i, j, start;

	while(scanf("%d", &n) == 1 && n > 0)//1 2 
	{
		start = 'A' + n - 1;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < i; j++)
			{
				printf(" ");
			}

			for(j = 0; j <= i ; j++)
			{
				printf("%c", start-j);
			}
			printf("\n");
		}		
	}

	return 0;
}
