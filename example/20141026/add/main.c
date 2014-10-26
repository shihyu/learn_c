#include <stdio.h>
#include "add.h"

int main(int argc, char *argv[])
{
    int sum;

    sum = add(10,20);
    printf("%d\n",sum);

    return 0;
}
