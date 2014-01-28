#include <stdio.h>
#include <string.h>

#define N 256

void count_char(char *s, int *p)
{
	while(*s)
	{
		p[*s++]++;
	}
}

int main()
{	
	char a[N];
	int b[N], i;

	while(gets(a) && a[0] != '\0')
	{
		bzero(b, sizeof(b));
		count_char(a, b);
		for(i = 0; i < N; i++)
		{
			if(b[i] != 0)
				printf("%c %d times.\n", i, b[i]);
		}
	}

	return 0;
}
