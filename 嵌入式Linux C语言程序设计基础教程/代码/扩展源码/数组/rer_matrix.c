#include <stdio.h>

#define m 3
#define n 3
int main()
{
	int a[m][n] = { {1, 2, 3},
			        {4, 5, 6},
			        {7, 8, 9}};
	int i, j, t;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < i; j++)
		{
			t = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = t;
		}
	}

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

