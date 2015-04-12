#include <stdio.h>
#include "opencv.h"
#include "calfeatures.h"

void tarin_feature_begin() {
    int   feature_vectors[64] = {0};
    float feature_vectors_table[10][64] = {0};
    char FilePathName[50];
    int i, j;
    FILE *pFile;

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            // 讀取圖檔路徑
            sprintf(FilePathName, "number1_bmp/%d/%d.bmp", i, j);
            // printf("%s\n",FilePathName);
            // 計算一張圖特徵
            cal_image_feature(feature_vectors, FilePathName);
            stats_features_vectors(i,  feature_vectors, feature_vectors_table);
        }
    }


    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 64; ++j) {
            printf("%f ",feature_vectors_table[i][j]);
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

void stats_features_vectors(int fildernum, int feature_vectors[64], float feature_vectors_table[][64]) {
    int i;

    for (i = 0; i < 64; ++i) {
        feature_vectors_table[fildernum][i] += feature_vectors[i];
    }
}

void cal_image_feature(int feature_vector[], char FilePathName[]) {
    IplImage *Image = NULL;
    int i, j, k;

    printf("\n%p[+]\n", Image);
    // load  image 
    Image = cvLoadImage(FilePathName, CV_LOAD_IMAGE_GRAYSCALE);
    printf("%p[-]\n", Image);

    if (Image == NULL) {
        fprintf(stderr, "Can not load image %s\n", FilePathName);
        exit(-1);
    }

    // change one dim to two dim via c++ template
    BwImage BlockA(Image);

    /*
    for (i = 0; i < Image->height; ++i) {
        for (j = 0; j < Image->width; ++j) {
            printf("%3d ", BlockA[i][j]);
        }

        printf("\n");
    }

    printf("\n");
    */ 

    k = 0;

    for (i = 0; i < Image->height; ++i) {
        for (j = 0; j < Image->width; ++j) {
            k = j + 1;

            if (k < Image->width && BlockA[i][j] != BlockA[i][k]) {
                feature_vector[i] += 1;
            }

        }
    }

    for (i = 0; i < Image->height; ++i) {
        for (j = 0; j < Image->width; ++j) {
            k = j + 1;


            if (k < Image->width && BlockA[j][i] != BlockA[k][i]) {
                feature_vector[i + 32] += 1;
            }
        }
    }

}

void stats_feature() {
}
