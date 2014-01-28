#include <stdio.h>
#include <math.h>

int main()
{
/*
	int m = 4453, n = 5767;
	int a = 5767, b = 4453;
	int c = a % b;
	*/
	int m, n, a, b, c;

	while(scanf("%d %d", &m, &n) == 2 && m > 0 && n > 0)
	{
		a = m > n ? m : n;
		b = m > n ? n : m;
		c = a % b;
		while(c != 0)
		{
			a = b;
			b = c;
			c = a % b;
		}
		printf("m, n:  max = %d, min = %d\n", b, m * n / b);
	}
	return 0;
}
