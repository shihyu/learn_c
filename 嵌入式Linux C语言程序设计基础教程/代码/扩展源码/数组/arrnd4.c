#include <stdio.h>

int main()
{
	int m = 2, n = 3;
	int *p[2];
	p[0] = &m;
	p[1] = &n;
	printf("&m = %p, &n = %p\np[0] = %p, p[1] = %p\n&p[0] = %p, &p[1] = %p\n&p = %p\n",
		&m, &n, p[0], p[1], &p[0], &p[1], &p);
	int i;
	for(i = 0; i < 2; i++)
	{
		printf("%d  %d  %d  ", *p[i], *(*(p+i)), p[i][0]);
	}
	printf("\n");


	return 0;
}
