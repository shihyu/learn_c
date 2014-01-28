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

    printf("%s\n", mystrcpy(a, b));

    strcpy(p, mystrcpy(a, b));
    printf("a=%s b=%s p=%s\n", a, b, p);


	mystrcat(p, mystrcat(a, b));
//	mystrcat(p, b);
	puts(p);
//	puts(p);

	return 0;	
}
