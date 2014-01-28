#include <stdio.h>
#include <string.h>

char * mystrcpy(char *dest, const char *src)
{
	char *p = dest;
	while(*dest++ = *src++);
	return p;
}

char * mystrcat(char *dest, const char *src)
{
	char *p = dest;
	while(*dest++);
	dest--;

	while(*dest++ = *src++);
	return p;
}


int main()
{	
	char a[128] = "asdfdsf";
	char *b = "tt";
	char p[128] = {0};

    printf("%s\n", strcat(a, b));

	mystrcat(p, mystrcat(a, b));
    printf("a=%s b=%s p=%s\n", a, b, p);

	return 0;	
}
