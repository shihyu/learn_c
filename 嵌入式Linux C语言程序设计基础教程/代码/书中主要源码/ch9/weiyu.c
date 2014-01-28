#include <stdio.h>

struct data
{
    unsigned int a: 2;
    unsigned int b: 4;
    unsigned int: 0;
    unsigned int c: 3;
}t;

int main()
{
    struct data *p;

    t.a = 3;
    t.b = 5;
    t.c = 6;

    printf("t.a=%d t.b=%d t.c=%d\n",
            t.a, t.b, t.c);

    p = &t;

    p->a = 2;
    p->b &= 0;
    p->c |= 1;

    printf("t.a=%d t.b=%d t.c=%d\n",
            t.a, t.b, t.c);

    return 0;
}
