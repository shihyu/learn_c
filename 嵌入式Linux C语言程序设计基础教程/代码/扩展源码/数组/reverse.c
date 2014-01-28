#include <stdio.h>

#define N 10
int main()
{
	char a[N];
	scanf("%s", a);
	int i, n = 0;
	while(a[n] != '\0')
	{
		n++;
	}

	for( i = n-1; i >= 0; i--)
	{
		printf("%c", a[i]);
	}
	printf("\n");

	return 0;
}
