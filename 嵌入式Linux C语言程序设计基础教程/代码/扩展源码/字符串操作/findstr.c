#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 255
int main()
{
	char a[] = "a0212222222222222xxxxxyuibdaeddfdfx";
	int n = 0;
	while(a[n])
	{
		n++;
	}
	/*
	int i = 0, j = n-1, t;
	while(i < j)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++;
		j--;
	}
	*/
	int i = 0, t;
	while(i < n/2)
	{
		t = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = t;
		i++;
	}
	puts(a);

	return 0;
}
