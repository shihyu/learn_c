#include <stdio.h>

#define R 2
#define C 3

int main()
{
	int a[][C] = {{1, 2, 3}, {4, 5, 6}};
	/*
	printf("a = %p, a+1=%p\n", a, a+1);
	printf("a[0] = %p, a[0]+1=%p\n", a[0], a[0]+1);
	printf("&a[0][0] = %p, &a[0][0]+1=%p\n", &a[0][0], &a[0][0]+1);
	printf("a[0][0] = %d, a[0][0]+1=%d\n", a[0][0], a[0][0]+1);
	*/
	printf("sizeof(a)= %d, sizeof(a[0])=%d\n", sizeof(a), sizeof(a[0]));
	printf("sizeof(a[0][0])= %d\n", sizeof(a[0][0]));
	int i, j;
	for(i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		for(j = 0; j < sizeof(a[0]) / sizeof(int); j++)
		{
			printf("%d ", *(*(a+i)+j) );//a[i][j]
		}	
		printf("\n");
	}
	
	

	return 0;
}
