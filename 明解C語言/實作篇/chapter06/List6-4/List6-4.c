/*
    確認未給定型別時會變成int型的現象
*/

#include  <stdio.h>

int func(a, b)
int a;
int b;
{
    struct {
        int x;
        int y;
    } z;

    z.x = a;
    z.y = b;

    printf("z.x = %d\n", z.x);
    printf("z.y = %d\n", z.y);

    return (z.x + z.y);
}

int main(void) {
    int  a = 1;
    int  b = 2;

    printf("func(a, b) = %d\n", func(a, b));

    system("PAUSE");
    return (0);
}
