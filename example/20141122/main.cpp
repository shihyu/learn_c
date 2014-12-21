#include <stdio.h>
#include "opencv.h"
// g++ -ggdb `pkg-config --cflags opencv` main.cpp -o main `pkg-config --libs opencv`

void tarin_feature_begin();

/* mode is 0 : train
 * mode is 1 : similar compare
 *
 * */
void cal_image_feature(int feature_vector[64], char *FilePathName);
void stats_feature();


int main(int argc, char *argv[]) {
    IplImage *Image = NULL;
    int i, j;

    // printf("argc=%d\n",argc);

    if (argc > 1) {
        printf("start similar compare\n");
#if 0
        printf("argv[0]=%s\n", argv[0]);
        printf("argv[1]=%s\n\n", argv[1]);

        Image = cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
        BwImage BlockA(Image);

        for (i = 0; i < Image->height; ++i) {
            for (j = 0; j < Image->width; ++j) {
                printf("%4d", BlockA[i][j]);
            }

            printf("\n");
        }

#endif

    } else {
        printf("start train\n");
        tarin_feature_begin();
    }

    return 0;
}


void tarin_feature_begin() {
    int feature_vector[64] = {0};
    char FilePathName[50];
    int i, j;

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            sprintf(FilePathName, "number1_bmp/%d/%d.bmp", i, j);
            cal_image_feature(feature_vector, FilePathName);
        }
    }
}

void cal_image_feature(int feature_vector[64], char *FilePathName) {
    IplImage *Image = NULL;
    int i, j;

    Image = cvLoadImage(FilePathName, CV_LOAD_IMAGE_GRAYSCALE);

    if (Image == NULL) {
        fprintf(stderr, "Can not load image %s\n", FilePathName);
        exit(-1);
    }

    BwImage BlockA(Image);

    for (i = 0; i < Image->height; ++i) {                                                                                                      
        for (j = 0; j < Image->width; ++j) {
            printf("%3d ", BlockA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void stats_feature() {
}
