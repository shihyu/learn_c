#include <stdio.h>

#define R 2
#define C 3

int main()
{
	int a[R][C] = {{1, 2, 3}, {4, 5, 6}};
	int *p;
	printf("%p, %p, %p, %p\n", p, p+1, a, a+1);
	p = &a[0][0];
	printf("%p, %p, %p, %p\n", p, p+1, &a[0][0], &a[0][0]+1);
	int i, j;
	printf("%d %d\n", sizeof(a), sizeof(a[0][0]));
	for(i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", *(p+i) );
		if((i+1) % C == 0)
			printf("\n");
	}
	for(i = 0; i < R; i++)
	{
		for(j = 0; j < C; j++)
		{
			printf("%d  ", *(p+C*i+j));//a[i][j]
		}
		printf("\n");
	}
	
	

	return 0;
}
