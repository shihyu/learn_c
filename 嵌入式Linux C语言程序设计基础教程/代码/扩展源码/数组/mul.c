#include <stdio.h>
#include <string.h>

#define m 2
#define n 3
#define k 4

int main()
{
	int a[m][n] = { {1, 1, 1},
			    	{1, 1, 1} };
	int b[n][k] = {{1, 1, 1, 1},
		           {1, 1, 1, 1},
		           {1, 1, 1, 1}};
	int c[m][k];
	int i, j, r;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < k; j++)
		{
			c[i][j] = 0;
			for(r = 0; r < n; r++)
			{
				c[i][j] += a[i][r] * b[r][j];
			}
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}
