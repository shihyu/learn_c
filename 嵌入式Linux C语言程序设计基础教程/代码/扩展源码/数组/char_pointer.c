#include <stdio.h>
#include <string.h>

int main()
{
	char a[100] = "abcde";
	char b[] = "1234";
	char *src, *dest;
	src = a;
	dest = b;

	while(*src++ = *dest++ );

	printf("%s, %s\n", a, b);

	return 0;
}
