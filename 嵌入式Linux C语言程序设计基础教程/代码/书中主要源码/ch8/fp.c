#include <stdio.h>

typedef int (*MFunc)(int, int);

int test(int a, int b, MFunc pFunc);
int plus(int a, int b);//函数声明
int minus(int, int);   //函数声明，缺省形参名称

int main()
{
    int x = 5, y = 8;
    MFunc  pFunc;

    pFunc = plus;
    printf("%d\n", (*pFunc)(x, y));

    pFunc = minus;
    printf("%d\n", (*pFunc)(x, y));

    printf("%d\n", test(15, 5, plus));
    printf("%d\n", test(15, 5, minus));

    return 0;
}

int plus(int a, int b)
{
    return (a+b);
}

int minus(int a, int b)
{
    return (a-b);
}

int test(int a, int b, MFunc pFunc)
{
    return ((*pFunc)(a, b));
}
