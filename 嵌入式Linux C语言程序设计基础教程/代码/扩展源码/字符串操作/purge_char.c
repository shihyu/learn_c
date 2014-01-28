#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 255
int main()
{
	char a[] = "a0212222222222222xxxxxyuibdaeddfdf";
	int count[N];
	memset(count, 0, sizeof(count));
	int i = 0;
	while(a[i])
	{
		count[a[i]]++;
		i++;
	}
	for(i = 0; i < N; i++)
	{
		if(count[i])
			printf("%c %d\n", i, count[i]);
	}

	return 0;
}
