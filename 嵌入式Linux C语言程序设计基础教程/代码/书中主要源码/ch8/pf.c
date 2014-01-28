#include <stdio.h>
#include <string.h>

char *mystring(void)
{
    char str[20];
    strcpy(str, "Welcome");
    return str;
}

int main()
{
    printf("%s\n", mystring());

    return 0;
}
