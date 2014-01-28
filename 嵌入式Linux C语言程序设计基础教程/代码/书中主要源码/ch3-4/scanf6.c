#include <stdio.h>

int main()
{
    int a;
    char ch;

    printf("input a number:");
    scanf("%d", &a);
    printf("a=%d\n", a);

    printf("input a character:");
    scanf("%*c%c", &ch);
    printf("ch=%c %d\n", ch, ch);

    return 0;
}
