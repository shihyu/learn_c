#include <stdio.h>

#define m 3
#define n 3
int main()
{
	int a[m][n] = { {1, 2, 3},
			        {4, 5, 6},
			        {7, 8, 9}};
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j <= i; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	
	printf("\n\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < i; j++)
			printf("  ");

		for(j = i; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}
