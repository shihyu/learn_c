#include <stdio.h>

void reverse(char *s, int start, int end)
{
	int i = start, j = end, t;
	while(i < j)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
		i++;
		j--;
	}
}

void part_reverse(char *s)
{
	char *p = s;
	int start = 0, end = 0;
/*	while(*s == ' ' && *s)
	{
		s++;
		start++;
		end++;
	}
*/	while(*s)
	{
		while(*s != ' ' && *s)
		{
			end++;
			s++;
		}
		end--;
		if(*s == '\0')
		{
			reverse(p, start, end);
		//	puts(p);
		}		
		else
		{
			printf("%d, %d\n", start, end);
			reverse(p, start, end);
		//	puts(p);
			end++;
			while(*s == ' ' && *s)
			{
				s++;
				end++;
			}
			start = end;
		}
	}
}

int main()
{
	char str[] = "          how    are    your    a";
	puts(str);
	part_reverse(str);
	puts(str);
	return 0;
}
