#include <stdio.h>
#include "opencv.h"
// g++ -ggdb `pkg-config --cflags opencv` main.cpp -o main `pkg-config --libs opencv`

int main(int argc, char *argv[]) {
    IplImage *Image = NULL;
    int i, j;

    printf("argc=%d\n",argc);

    if (argc > 1) {
        printf("argv[0]=%s\n",argv[0]);
        printf("argv[1]=%s\n\n",argv[1]);

        Image = cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
        BwImage BlockA(Image);

        for (i = 0; i < Image->height; ++i) {
            for (j = 0; j < Image->width; ++j) {
                printf("%4d", BlockA[i][j]);
            }
            printf("\n");
        }

    } else {
        printf("argv[0]=%s\n",argv[0]);
        printf("example ./main file path");
    }

    return 0;
}
