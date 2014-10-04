#include "opencv.h"
#include <stdio.h>

using namespace cv;

// CV_LOAD_IMAGE_UNCHANGED -1        原圖影像
// CV_LOAD_IMAGE_GRAYSCALE 0             灰階
// CV_LOAD_IMAGE_COLOR 1                    彩色
// CV_LOAD_IMAGE_ANYDEPTH 2           任何彩度
// CV_LOAD_IMAGE_ANYCOLOR 4           任何彩色

int main(int argc, char* argv[]) {
    const char* FileName = "lena.jpg";
    IplImage* Image = NULL;

    // 顧名思義,就是載入圖片的意思,它的使用方法為 IplImage* cvLoadImage("檔案名稱",參數);
    Image = cvLoadImage(FileName, CV_LOAD_IMAGE_COLOR);

    //如果讀入圖像失敗
    if (Image == NULL) {
        fprintf(stderr, "Can not load image %s\n", FileName);
        return -1;
    }


    //顯示圖像
    cvShowImage("Show Image", Image);

    //此函數等待按鍵，按鍵盤任意鍵就返回
    waitKey();
    return 0;
}
