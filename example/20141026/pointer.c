#include <stdio.h>

int main(void)
{
    
    int i ,j;
    int a = 100;

    int one_dim_array[5] = {10,20,30,40,50};

    int two_dim_array[3][2] = {{10,20},
                               {30,40},
                               {50,60}};

    int *pa = &a;

    // int *parray = &one_dim_array[0];
    int *parray = one_dim_array;

    printf("%p\n", &one_dim_array[0]);
    printf("%p\n", one_dim_array);

    printf("%ld\n",sizeof(one_dim_array));
    printf("%ld\n",sizeof(&one_dim_array[0]));





    int (*pparray)[2] = two_dim_array;



    int *pparray1[2] = two_dim_array;

    printf("%d\n",*pa);


    for (i = 0; i < 5; ++i) {
        printf("parray[%d] = %d\n",i, parray[i]);
    }

    printf("\n\n");

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 2; ++j) {
            printf("pparray[%d][%d]=%d\n",i,j,pparray[i][j]);
        }
    }

    return 0;
}
