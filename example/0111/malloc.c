#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    int* p = (int*)malloc(20); // int a[5];
    int i;
    printf("%p\n", p);
    *p = 100;
    *(p + 1) = 200;
    *(p + 2) = 300;
    *(p + 3) = 400;
    *(p + 4) = 500;

    for (i = 0; i < 5; ++i) {
        // printf("%d\n",p[i]);
        printf("%d\n", *(p + i));
    }

    free(p);
    p = NULL;
    return 0;
}
