#include <stdio.h>

#define N 128

inline void reverse(char *s, int index, int n)
{
	int i, t;
	for(i = 0; i < n/2; i++)	
	{
		t = s[index+i];
		s[index+i] = s[n-1-i+index];
		s[n-1-i+index] = t;
	}
}
inline void part_reverse(char *s)
{
	char *p = s;
	int index = 0, n = 0, i = 0;
	
	while(*p++) n++;

	reverse(s, 0, n);

	p = s;
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
		//if(*s == ' ')
		//{
			printf("%d %d\n", index, n);
			reverse(p, index, n);
		//}
	}

}

int main()
{
	//char a[N] = "    beijing      to       welcome  ";
	char a[N] = "12345   ";
	part_reverse(a);
	puts(a);

	return 0;
}
