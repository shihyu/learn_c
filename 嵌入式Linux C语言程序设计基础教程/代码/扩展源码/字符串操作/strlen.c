#include <stdio.h>
#define N 1024
int get_length(char *);

int main()
{
	int len;
	char a[N];
	while(gets(a) && a[0] != '\0')
	{
		len = get_length(a);
		printf("%d\n", len);
	}
}

int get_length(char *s)
{
	int n = 0;
	while(*s++)
		n++;

	return n;
}
