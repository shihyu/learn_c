#include <stdio.h>
#include "opencv.h"
#include "main.h"
// g++ -ggdb `pkg-config --cflags opencv` main.cpp -o main `pkg-config --libs opencv`

int main(int argc, char *argv[]) {

    if (argc > 1) {
        printf("start similar compare\n");
    } else {
        printf("start train\n");
        tarin_feature_begin();
    }

    return 0;
}

void stats_features_vectors(int fildernum, int feature_vectors[64], float feature_vectors_table[][64]) {
    int i;

    for (i = 0; i < 64; ++i) {
        feature_vectors_table[fildernum][i] += feature_vectors[i];
    }
}

void tarin_feature_begin() {
    int   feature_vectors[64] = {0};
    float feature_vectors_table[10][64] = {0};
    char FilePathName[50];
    int i, j;
    FILE *pFile;

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            sprintf(FilePathName, "number1_bmp/%d/%d.bmp", i, j);
            // printf("%s\n",FilePathName);
            cal_image_feature(feature_vectors, FilePathName);
            stats_features_vectors(i,  feature_vectors, feature_vectors_table);
        }
    }

    for (i = 0; i < 10; ++i) {
        sprintf(FilePathName, "%d.txt", i);
        pFile = fopen(FilePathName, "w");

        for (j = 0; j < 64; ++j) {
            feature_vectors_table[i][j] /= 10.0;
            fprintf(pFile, "%f\n", feature_vectors_table[i][j]);
        }

        fclose(pFile);
    }
}

void cal_image_feature(int feature_vector[], char FilePathName[]) {
    IplImage *Image = NULL;
    int i, j;

    printf("\n%p[+]\n", Image);
    Image = cvLoadImage(FilePathName, 0);
    printf("%p[-]\n", Image);

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
