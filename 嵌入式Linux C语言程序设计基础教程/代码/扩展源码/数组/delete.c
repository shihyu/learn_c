#include <stdio.h>

#define N 1024

int main()
{
	int a[N], last, i = 0, j, k;
	char flag;
	flag = 'y';
	while(flag == 'y' || flag == 'Y')
	{
		printf("input: ");
		scanf("%d", &a[i++]);

		getchar();
		printf("continue?[y/n]: ");
		scanf("%c", &flag);
	}
	last = i-1;
	for(i = 0; i <= last; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
	
	for(i = 0; i < last; i++)
	{
		for(j = i+1; j <= last;)
		{	
			
			if(a[i] == a[j])
			{
				for(k = j; k <= last; k++)
					a[k] = a[k+1];
				last--;
			}
			else
				j++;
		}
	}

	for(i = 0; i <= last; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");





	return 0;
}
