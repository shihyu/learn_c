#include <stdio.h>

#define N 128

int char_to_int(char *s)
{
	int ret = 0;
	while(*s)
	{
		ret = ret * 10 + *s - '0';
		s++;
	}
	return ret;
}

void int_to_char(int m, char *s)
{
	char *p = s, t;
	if(m == 0)
		*s++ = '0';
	while(m != 0)
	{
		*s++ = m % 10 + '0';
		m = m / 10;
	}
	*s = '\0';
	s--;
	while(p < s)
	{
		t = *p;
		*p = *s;
		*s = t;
		p++;
		s--;
	}
		
}


int main()
{
	char a[N] = "123";
	char b[N];
	int m = 123;

	printf("%d\n", char_to_int(a));
	int_to_char(m, b);

	puts(b);

	return 0;
}
