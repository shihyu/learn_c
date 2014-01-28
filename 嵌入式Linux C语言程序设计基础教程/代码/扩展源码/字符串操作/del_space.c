#include <stdio.h>

#define N 1024

void del_space(char *s)
{
	char *q = s;
	while(*s)
	{
		if(*s != ' ')
		{
			*q = *s;
			q++;
		}
		s++;
	}
	*q = '\0';
}


int main()
{
	char a[N];
	while(gets(a) && a[0] != '\0')
	{
		del_space(a);
		puts(a);
	}


	return 0;
}
