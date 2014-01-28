#include <stdio.h>

#define N 1024
int main()
{
	int a[N], last, i=0, j, k;
	char flag;

	flag = 'Y';//getchar()
	while(flag == 'y' || flag == 'Y')
	{
		printf("input:");
		scanf("%d", &a[i++]);
		printf("continue?[y/n]: ");
		getchar();
		flag = getchar();
	}
	
	last = i-1;
	for(i = 0; i <= last; i++)
	{
		printf("%d ", a[i]);
	}
/*
	printf("\n");
	int a[N] = {1, 5, 7, 5, 7, 8};
	int last = 5;
	int i, j, k;

*/

	printf("\n");
	
	for(i = 0; i < last; i++)
	{
		for(j = i+1; j <= last;)
		{
			if(a[i] == a[j])
			{
				for(k = j+1; k <= last;k++)
					a[k-1] = a[k];
				last--;
			}
			else
				j++;
		}
	}	

	for(i = 0; i <= last; i++)
		printf("%d  ", a[i]);
	printf("\n");
	return 0;
}
