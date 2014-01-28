#include <stdio.h>
#include <string.h>

#define N 60

int main()
{
    char s1[N], s2[N];
    int t;

    printf(">");
    scanf("%s%s", s1, s2);
    t = strcmp(s1, s2);
    if (t == 0)
        printf("s1 = s2\n");
    else if (t > 0)
        printf("s1 > s2\n");
    else
        printf("s1 < s2\n");

    return 0;
}
