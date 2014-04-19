#include <stdio.h>

int main(int argc, char *argv[]) {
    int value;
    unsigned char  image1[10];

    scanf("%d", &value);

    unsigned char  image2[value];

    printf("%ld\n", sizeof(image2));




    return 0;
}
