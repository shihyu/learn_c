#include <stdio.h>
#define N 1024

int get_length(char *s)
{
	int n = 0;
	while(*s++)
		n++;

	return n;
}
void reverse(char *s)
{
	int n = get_length(s);//"abc" 3
	int i = 0, j = n-1;
	char t;
	while(i < j)
	{
//		s[i]  s[j]
		t = s[i];
		s[i] = s[j];
		s[j] = t;
		i++;
		j--;
	}
}

int main()
{
	char a[N];
	while(gets(a) && a[0] != '\0')
	{
		reverse(a);
		puts(a);
	}
	return 0;
}

