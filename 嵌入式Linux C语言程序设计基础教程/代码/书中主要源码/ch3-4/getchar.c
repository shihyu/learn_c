#include <stdio.h>

int main()
{
    int ch;
    printf("Enter a character:");

    while ((ch = getchar()) != EOF)
        printf("%c--->%#x\n", ch, ch);

    printf("end main\n");

    return 0;
}
