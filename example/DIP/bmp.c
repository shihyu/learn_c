#if 1
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef unsigned int  DWORD;
typedef unsigned int  LONG;

int main(void) {
    FILE* fPtr;
    int i, j;
    char fileName[32], RGBQUAD[4][256];
    unsigned char* PIXEL;
    unsigned char* temp;

    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;

    //將資料從檔案輸入到記憶體
    printf("Open FileName: ");
    scanf("%s", fileName);

    fPtr = fopen(fileName, "rb");

    fread((char*)&bfType, sizeof(WORD), 1, fPtr);
    fread((char*)&bfSize, sizeof(DWORD), 1, fPtr);
    fread((char*)&bfReserved1, sizeof(WORD), 1, fPtr);
    fread((char*)&bfReserved2, sizeof(WORD), 1, fPtr);
    fread((char*)&bfOffBits, sizeof(DWORD), 1, fPtr);
    fread((char*)&biSize, sizeof(DWORD), 1, fPtr);
    fread((char*)&biWidth, sizeof(LONG), 1, fPtr);
    fread((char*)&biHeight, sizeof(LONG), 1, fPtr);
    fread((char*)&biPlanes, sizeof(WORD), 1, fPtr);
    fread((char*)&biBitCount, sizeof(WORD), 1, fPtr);
    fread((char*)&biCompression, sizeof(DWORD), 1, fPtr);
    fread((char*)&biSizeImage, sizeof(DWORD), 1, fPtr);
    fread((char*)&biXPelsPerMeter, sizeof(LONG), 1, fPtr);
    fread((char*)&biYPelsPerMeter, sizeof(LONG), 1, fPtr);
    fread((char*)&biClrUsed, sizeof(DWORD), 1, fPtr);
    fread((char*)&biClrImportant, sizeof(DWORD), 1, fPtr);
    fread(RGBQUAD[0], sizeof(RGBQUAD), 1, fPtr);

    PIXEL = (unsigned char*)malloc(biHeight * biWidth * sizeof(unsigned char));
    temp = (unsigned char*)malloc(biHeight * biWidth * sizeof(unsigned char));

    fread(PIXEL, biHeight * biWidth * sizeof(unsigned char), 1, fPtr);
    fclose(fPtr);

    //顯示檔案資訊
    printf("FILE_HEADER\n");
    printf("bfType=%d\t\t\n", bfType);
    printf("bfSize=%d\t\t\n",       bfSize);
    printf("bfReserved1=%d\t\n",    bfReserved1);
    printf("bfReserved2=%d\t\n",    bfReserved2);
    printf("bfOffBits=%d\t\n",      bfOffBits);
    printf("INFO_HEADER\n");
    printf("biSize=%d\t\t\n",       biSize);
    printf("biWidth=%d\t\n",        biWidth);
    printf("biHeight=%d\t\n",       biHeight);
    printf("biPlanes=%d\t\n",       biPlanes);
    printf("biBitCount=%d\t\n",     biBitCount);
    printf("biCompression=%d\t\n",  biCompression);
    printf("biSizeImage=%d\t\n",    biSizeImage);
    printf("biXPelsPerMeter=%d\n",  biXPelsPerMeter);
    printf("biYPelsPerMeter=%d\n",  biYPelsPerMeter);
    printf("biClrUsed=%d\t\n",      biClrUsed);
    printf("biClrImportant=%d\t\n", biClrImportant);


    //將圖片資訊暫存到TEMP裡面
    for (i = biHeight - 1; i > 0; i--) {
        for (j = biWidth - 1; j > 0; j--) {
            *(temp + i * biWidth + j) = *(PIXEL + i * biWidth + j);
        }
    }

    // dump temp
    for (i = biHeight - 1; i > 0; i--) {
        for (j = biWidth - 1; j > 0; j--) {
            printf("%3d ",*(temp + i * biWidth + j));
        }
        printf("\n");
    }

    //將資訊反轉180度
    for (i = 0; i < biHeight; i++) {
        for (j = 0; j < biWidth; j++) {
            // PIXEL[biHeight - 1 - i][biWidth - 1 - j] = *(temp + i * biWidth + j);
            // PIXEL[511 - i][511 - j] = temp[i][j];
           *(PIXEL + (biHeight - 1 - i) * biWidth + biWidth - 1 - j) = *(temp + i * biWidth + j);
        }
    }

    //將資料從記憶體輸出到檔案
    printf("輸入旋轉後儲存的名稱：\t");
    scanf("%s", fileName);

    fPtr = fopen(fileName, "wb");

    fwrite((char*)&bfType, sizeof(WORD), 1, fPtr);
    fwrite((char*)&bfSize, sizeof(DWORD), 1, fPtr);
    fwrite((char*)&bfReserved1, sizeof(WORD), 1, fPtr);
    fwrite((char*)&bfReserved2, sizeof(WORD), 1, fPtr);
    fwrite((char*)&bfOffBits, sizeof(DWORD), 1, fPtr);
    fwrite((char*)&biSize, sizeof(DWORD), 1, fPtr);
    fwrite((char*)&biWidth, sizeof(LONG), 1, fPtr);
    fwrite((char*)&biHeight, sizeof(LONG), 1, fPtr);
    fwrite((char*)&biPlanes, sizeof(WORD), 1, fPtr);
    fwrite((char*)&biBitCount, sizeof(WORD), 1, fPtr);
    fwrite((char*)&biCompression, sizeof(DWORD), 1, fPtr);
    fwrite((char*)&biSizeImage, sizeof(DWORD), 1, fPtr);
    fwrite((char*)&biXPelsPerMeter, sizeof(LONG), 1, fPtr);
    fwrite((char*)&biYPelsPerMeter, sizeof(LONG), 1, fPtr);
    fwrite((char*)&biClrUsed, sizeof(DWORD), 1, fPtr);
    fwrite((char*)&biClrImportant, sizeof(DWORD), 1, fPtr);
    fwrite(RGBQUAD[0], sizeof(RGBQUAD), 1, fPtr);
    fwrite(PIXEL, biHeight * biWidth * sizeof(unsigned char), 1, fPtr);
    fclose(fPtr);
    return 0;
}

#else
#include <iostream>
#include <fstream>

using namespace std;

typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef unsigned int  DWORD;
typedef unsigned int  LONG;

int main(void) {
    fstream file;
    int i, j;
    char fileName[32], RGBQUAD[4][256], PIXEL[512][512], temp[512][512];


    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;

    //將資料從檔案輸入到記憶體
    cout << "Open FileName: ";
    cin >> fileName;

    file.open(fileName, ios::in | ios::binary);
    file.read((char*)&bfType, sizeof(WORD));
    file.read((char*)&bfSize, sizeof(DWORD));
    file.read((char*)&bfReserved1, sizeof(WORD));
    file.read((char*)&bfReserved2, sizeof(WORD));
    file.read((char*)&bfOffBits, sizeof(DWORD));
    file.read((char*)&biSize, sizeof(DWORD));
    file.read((char*)&biWidth, sizeof(LONG));
    file.read((char*)&biHeight, sizeof(LONG));
    file.read((char*)&biPlanes, sizeof(WORD));
    file.read((char*)&biBitCount, sizeof(WORD));
    file.read((char*)&biCompression, sizeof(DWORD));
    file.read((char*)&biSizeImage, sizeof(DWORD));
    file.read((char*)&biXPelsPerMeter, sizeof(LONG));
    file.read((char*)&biYPelsPerMeter, sizeof(LONG));
    file.read((char*)&biClrUsed, sizeof(DWORD));
    file.read((char*)&biClrImportant, sizeof(DWORD));
    file.read(RGBQUAD[0], sizeof(RGBQUAD));
    file.read(PIXEL[0], sizeof(PIXEL));
    file.close();

    //顯示檔案資訊
    cout << "FILE_HEADER\n"
         << "bfType=\t\t"       << bfType       << '\n'
         << "bfSize=\t\t"       << bfSize       << '\n'
         << "bfReserved1=\t"    << bfReserved1  << '\n'
         << "bfReserved2=\t"    << bfReserved2  << '\n'
         << "bfOffBits=\t"      << bfOffBits    << "\n\n"
         << "INFO_HEADER\n"
         << "biSize=\t\t"       << biSize       << '\n'
         << "biWidth=\t"        << biWidth      << '\n'
         << "biHeight=\t"       << biHeight     << '\n'
         << "biPlanes=\t"       << biPlanes     << '\n'
         << "biBitCount=\t"     << biBitCount   << '\n'
         << "biCompression=\t"  << biCompression    << '\n'
         << "biSizeImage=\t"    << biSizeImage      << '\n'
         << "biXPelsPerMeter="  << biXPelsPerMeter  << '\n'
         << "biYPelsPerMeter="  << biYPelsPerMeter  << '\n'
         << "biClrUsed=\t"      << biClrUsed        << '\n'
         << "biClrImportant=\t" << biClrImportant   << "\n\n";

    //將圖片資訊暫存到TEMP裡面
    for (i = 511; i > 0; i--) {
        for (j = 511; j > 0; j--) {
            temp[i][j] = PIXEL[i][j];
        }
    }

    //將資訊反轉180度
    for (i = 0; i < 512; i++) {
        for (j = 0; j < 512; j++) {
            PIXEL[511 - i][511 - j] = temp[i][j];
        }
    }

    //將資料從記憶體輸出到檔案
    cout << "輸入旋轉後儲存的名稱：\t";
    cin >> fileName;

    file.open(fileName, ios::out | ios::binary);
    file.write((char*)&bfType, sizeof(WORD));
    file.write((char*)&bfSize, sizeof(DWORD));
    file.write((char*)&bfReserved1, sizeof(WORD));
    file.write((char*)&bfReserved2, sizeof(WORD));
    file.write((char*)&bfOffBits, sizeof(DWORD));
    file.write((char*)&biSize, sizeof(DWORD));
    file.write((char*)&biWidth, sizeof(LONG));
    file.write((char*)&biHeight, sizeof(LONG));
    file.write((char*)&biPlanes, sizeof(WORD));
    file.write((char*)&biBitCount, sizeof(WORD));
    file.write((char*)&biCompression, sizeof(DWORD));
    file.write((char*)&biSizeImage, sizeof(DWORD));
    file.write((char*)&biXPelsPerMeter, sizeof(LONG));
    file.write((char*)&biYPelsPerMeter, sizeof(LONG));
    file.write((char*)&biClrUsed, sizeof(DWORD));
    file.write((char*)&biClrImportant, sizeof(DWORD));
    file.write(RGBQUAD[0], sizeof(RGBQUAD));
    file.write(PIXEL[0], sizeof(PIXEL));
    file.close();
    return 0;
}
#endif
