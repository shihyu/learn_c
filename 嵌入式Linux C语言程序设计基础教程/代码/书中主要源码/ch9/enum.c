#include <stdio.h>

enum TimeofDay
{
    morning,
    afternoon,
    evening
};

int main()
{
    int i, j;
    enum TimeofDay a[10];

    printf("sizeof=%d\n", sizeof(enum TimeofDay));

    j = morning;
    for (i = 0; i < 10; i++)
    {
        a[i] = j;
        j++;
        if (j > evening)
            j = morning;
    }

    for (i = 0; i < 10; i++)
    {
        switch (a[i])
        {
            case morning: printf("%d morning\n", a[i]); break;
            case afternoon: printf("%d afternoon\n", a[i]); break;
            case evening: printf("%d evening\n", a[i]); break;
            default:break;
        }
    }

    return 0;
}
