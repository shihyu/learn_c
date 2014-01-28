#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 255
int main()
{
	//char a[] = "a0212222222222222xxxxxyuibdaeddfdfx";
	char a[1024];
	int n = 0, i, t;
	
	while(gets(a) && a[0] != '\0')
	{
		n = 0;
		while(a[n])
		{
			n++;
		}
		i = 0;
		while(i < n/2)
		{
			t = a[i];
			a[i] = a[n-1-i];
			a[n-1-i] = t;
			i++;
		}
		puts(a);
	}

	return 0;
}
