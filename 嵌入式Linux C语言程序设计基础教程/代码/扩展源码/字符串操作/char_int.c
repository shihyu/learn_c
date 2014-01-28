#include <stdio.h>
#include <string.h>

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
{//123
	char *p = s, t;
	while(m)
	{
		*s++ = m % 10 + '0';
		m = m / 10;
	}
	*s = '\0';
	//"321"
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

void reverse(char *a, int index, int n)
{
	int i, t;
	for(i = 0; i < n/2; i++)//a[i+index] a[n-1-i+index]
	{
		t = a[i+index];
		a[i+index] = a[n-1-i+index];
		a[n-1-i+index] = t;
	}
}
void part_reverse(char *s)
{
	char *p = s;
	int index, n, i;
	i = n = index = 0;

	reverse(s, 0, strlen(s));//" abcf"  index 0 n 3
	puts(s);
	
	while(*s)
	{
		while(*s && *s == ' ')
		{
			s++;
			i++;
		}
		index = i;
		n = 0;
		while(*s && *s != ' ')
		{
			s++;
			i++;
			n++;
		}
		reverse(p, index, n);		
	}
}

void count_char(char *s, int *c)
{
	while(*s)
	{
		c[*s]++;
		s++;
	}
}

int main()
{
	char a[1024];
	
	int b[256], i = 0;

	while(gets(a) && a[0] != '\0')
	{
		bzero(b, 256 * sizeof(int));
		count_char(a, b);
		i = 0;
		while(i < 256)
		{
			if(b[i])
				printf("%c %d times\n", i, b[i]);
			i++;
		}
	}


	

/*	char a[] = "abc";
	part_reverse(a);
	puts(a);
	char a[N] = "123";
	int m = char_to_int(a);
	printf("%d\n", m);


	int n = 123;
	char b[N];
	bzero(b, N);
	int_to_char(n, b);
	puts(b);

*/

	return 0;
}
