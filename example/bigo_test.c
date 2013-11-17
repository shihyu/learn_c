#include <stdio.h>

void test()
{
        printf("test\n");

}

int main()
{
    int bound, i, j , n = 8;
    
    for (bound = 1 ; bound <= n; bound *= 2) 
    {
        printf("1\n");
        for (i = 0; i < bound; ++i)
        {
            printf("2\n");
            for (j = 0; j < n; j += 2)
            {
                printf("2-1\n");
                /* code */
            }

            for (j = 1; j < n; j *=2)
            {
                printf("2-2\n");
                /* code */
            }
        }
    }
    test();
    return 0;
}
