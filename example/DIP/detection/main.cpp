#include <stdio.h>
#include "opencv.h"

// g++ -ggdb `pkg-config --cflags opencv` main.cpp -o main `pkg-config --libs opencv`

using namespace cv;

void features_train() {
    int i, j, k;
    int feature_veotors[2][32] = {0};
    const char* FileName = "f0002_01_30_001.bmp";
    IplImage* Image = NULL;

    Image = cvLoadImage(FileName, CV_LOAD_IMAGE_GRAYSCALE);

    if (Image == NULL) {
        fprintf(stderr, "Can not load image %s\n", FileName);
        exit(-1);
    }

    BwImage BlockA(Image);

    k = 0;
    for (i = 0; i < Image->height; ++i) {
        for (j = 0; j < Image->width; ++j) {
            k = j + 1;
            if (k < Image->width && BlockA[i][j] != BlockA[i][k]) {
                feature_veotors[0][i] += 1;
            }

            if (k < Image->width && BlockA[j][i] != BlockA[k][i]) {
                feature_veotors[1][i] += 1;
            }
        }
    }

    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 32; ++j) {
            printf("%3d",feature_veotors[i][j]);
        }
        printf("\n");
    }

#if 1
    for (i = 0; i < Image->height; ++i) {
        for (j = 0; j < Image->width; ++j) {
            printf("%3d ", BlockA[i][j]);
        }
        printf("\n");
    }

    cvShowImage("Show Image", Image);
    waitKey();
#endif
}

int main(int argc, char *argv[])
{

    features_train();
    
    return 0;
}
