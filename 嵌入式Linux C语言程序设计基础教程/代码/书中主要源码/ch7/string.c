#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char s[] = "Welcome";
    char *p, *q, t;

    char *r = "dfd";
    (*r)++;
    p = s;
    q = s + strlen(s) - 1;

    while (p < q)
    {
        t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }

    printf("%s\n", s);

    return 0;
}
