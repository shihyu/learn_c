#include <stdio.h>

#define R 2
#define C 3
int main()
{
	int a[2][3] = {1, 2, 3, 4, 5, 6};
	int *p[2], i, j;
	p[0] = a[0];
	p[1] = a[1];
	for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		for(j = 0; j < sizeof(a[0]) / sizeof(int); j++)
		{
			printf("%d   %d   %d   ", *(p[i]+j), *(*(p+i)+j), p[i][j] );//a[i][j]
		}
		printf("\n");
	}







	return 0;
}
