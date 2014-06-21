#include <stdio.h>
#define LEN 10

// int *p = a;
void test(int *p) {
    int i;

    for ( i = 0; i < LEN; i++ ) {
        p[i] = p[i] + 10;
    }

}

int main( int argc, char **argv )
{
    int a[LEN] = {1,2,3,4,5,6,7,8,9,10};
    int i;

    printf("modify before : ");
    for ( i = 0; i < LEN; i++ ) {
        printf("%d ", a[i]);
    }

    test(a); // call test function modify
    printf("\nmodify after : ");

    for ( i = 0; i < LEN; i++ ) {
        printf("%d ", a[i]);
    }
    
    return 0;
}
