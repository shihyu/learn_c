#include <stdio.h>

int f(int n)
{
	if(n == 0 || n == 1)
		return 1;
	return n * f(n-1);
}

int fib(int n)
{
	if(n == 1 || n == 2)
		return 1;
	return fib(n-1)+fib(n-2);
}

int main()
{
	int n = 5;
	printf("%d\n", f(5));
	printf("%d\n", fib(5));


	return 0;
}
