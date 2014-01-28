#include <stdio.h>
#include <stdlib.h>

int fun_int(const void *p, const void *q);
int fun_float(const void *p, const void *q);
int fun_string(const void *p, const void *q);

int main()
{
    int a[] = {98, 1, 24, 15, 78, 29, 36, 10, 91}, i;
    float b[] = {34.213, 92.123, 14, 91.231, 55, 60.345, 120.1};
    char *c[] = {"hello", "about", "who", "apple", "baname", "a", "zoo"};

    qsort(a, sizeof(a)/sizeof(int), sizeof(int), fun_int);
    for (i = 0; i < sizeof(a)/sizeof(int); i++)
        printf("%d ", a[i]);
    printf("\n");

    qsort(b, sizeof(b)/sizeof(float), sizeof(float), fun_float);
    for (i = 0; i < sizeof(b)/sizeof(float); i++)
        printf("%f ", b[i]);
    printf("\n");

    qsort(c, sizeof(c)/sizeof(char *), sizeof(char *), fun_string);
    for (i = 0; i < sizeof(c)/sizeof(char *); i++)
        printf("%s ", c[i]);
    printf("\n");

    return 0;
}

int fun_int(const void *p, const void *q)
{
    return (*(int const *)p - *(int const *)q);
}

int fun_float(const void *p, const void *q)
{
    float t = *(float const *)p - *(float const *)q;
    
    if (t > 1e-6)
        return 1;
    else if (t < -1e-6)
        return -1;
    else
        return 0;
}

int fun_string(const void *p, const void *q)
{
    return strcmp(*( char * const * )p, *( char * const *)q);
}
