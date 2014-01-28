#include <stdio.h>

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
	char p[128];
	p[0] = '\0';
	mystrcat(p, mystrcat(a, b));
//	mystrcat(p, b);
	puts(p);
//	puts(p);

	return 0;	
}
