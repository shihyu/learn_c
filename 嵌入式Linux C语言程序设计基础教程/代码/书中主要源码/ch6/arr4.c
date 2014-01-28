#include <stdio.h>

#define DEBUG 1

int main()
{
    int a[3][4] = {{8, 2, 6, 4}, {1, 4, 7, 9}}, i, j;;

#if DEBUG
    a++;
    a[0]++;
    a[1]++;
    a[2]++;
    a[3]++;
#endif

    printf("a   :%p   a+1   :%p\n\n", a, a+1);

    printf("a[0]:%p   a[0]+1:%p   &a[0][1]=%p\n", a[0], a[0]+1, &a[0][1]);
    printf("a[1]:%p   a[1]+1:%p   &a[1][1]=%p\n", a[1], a[1]+1, &a[1][1]);
    printf("a[2]:%p   a[2]+1:%p   &a[2][1]=%p\n", a[2], a[2]+1, &a[2][1]);
    printf("a[3]:%p   a[3]+1:%p   &a[3][1]=%p\n", a[3], a[3]+1, &a[3][1]);

    return 0;
}

