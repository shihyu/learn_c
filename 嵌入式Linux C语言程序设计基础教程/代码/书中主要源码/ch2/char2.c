#include <stdio.h>

int main()
{
    char c1 = 'a', c2 = 'b', c3 = 'c';
    char c4 = '\101', c5 = '\116';

    printf("a%c b%c\tabc%c\n", c1, c2, c3);
    printf("\t\b%c %c\n", c4, c5);

    return 0;
}
