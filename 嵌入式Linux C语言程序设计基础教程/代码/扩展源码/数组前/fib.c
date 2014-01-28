#include <stdio.h>
int main()
{
	int n, i, value;
	int n1, n2;
	while(scanf("%d", &n) == 1 && n > 0)
	{
		n1 = 1;
		n2 = 1;
		value = 1;
		for(i = 3; i <= n; i++)
		{
			value = n1 + n2;
			n1 = n2;
			n2 = value;
		}
		printf("fib(%d) = %d\n", n, value);
	}
}
