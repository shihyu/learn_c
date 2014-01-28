#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char s1[] = "Welcome";
    char s2[] = "to";
    char s3[] = "farsight";

    char* a1[3] = {s1, s2, s3};
    char *a2[3] = {"Welcome", "to", "farsight"};
    char **p;
    int i;

    p = a1;
    printf("array1:%s %s %s\n", a1[0], a1[1], a1[2]);

    for (i = 0; i < sizeof(a1) / sizeof(char *); i++)
        printf("%s ", *(p+i));
    printf("\n");

    p = a2;
    printf("array2:%s %s %s\n", a2[0], a2[1], a2[2]);
    for (i = 0; i < sizeof(a1) / sizeof(char *); i++)
        printf("%s ", *(p+i));
    printf("\n");



    return 0;
}
