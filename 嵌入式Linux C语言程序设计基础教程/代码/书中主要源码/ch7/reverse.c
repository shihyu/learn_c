#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "welcome";
    char *p, *q, t;

    printf("%s\n", s);

    p = s;
    q = s + strlen(s)-1;

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

#if 0
    while (*s != '\0')
    {
        num = num * 10 + *s - '0';
        s++;
    }
#endif
