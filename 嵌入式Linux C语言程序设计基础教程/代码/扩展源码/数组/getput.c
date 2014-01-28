#include <stdio.h>

int main()
{
	char a, b;
	a = getchar();//scanf("%c", &a);
	putchar(a);

	getchar();
	b = getchar();
	putchar(b);
	printf("%d\n", b);

	return 0;
}
