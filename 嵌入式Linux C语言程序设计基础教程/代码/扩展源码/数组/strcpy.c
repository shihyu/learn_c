#include <stdio.h>
#define N 20
int main()
{
	char a[N];
    char b[] = "abcde";
	char *src, *dest;
	src = b;
	dest = a;
	/*
	int i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	*/

	/*
	while(*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	*/
	
	/*
	while(*src)
		*dest++ = *src++;
	*dest = '\0';
	*/
	while(*dest++ = *src++);

	printf("%s %s\n", a, b);




	return 0;
}
