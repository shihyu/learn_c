#include <stdio.h>
#include "add.h"
#include "mul.h"

int main(void) {
    int (*fp)(int,int) = add; 
    printf("%d\n", add(10, 20));
    printf("%d\n", mul(10, 20));
    printf("\nfp address=%p\n",*(void**)&fp);
    return 0;
}
