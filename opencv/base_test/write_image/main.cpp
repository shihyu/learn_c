#include "opencv.h"
#include <stdio.h>

using namespace cv;
using namespace std;

// CV_LOAD_IMAGE_UNCHANGED -1        原圖影像
// CV_LOAD_IMAGE_GRAYSCALE 0             灰階
// CV_LOAD_IMAGE_COLOR 1                    彩色
// CV_LOAD_IMAGE_ANYDEPTH 2           任何彩度
// CV_LOAD_IMAGE_ANYCOLOR 4           任何彩色

int main(int argc, char* argv[]) {
    int i, j;
    const char* FileName = "lena.jpg";
    IplImage* Orig_Image = NULL;  // 原始圖使用的指標
    IplImage* Modify_Image = NULL;  // 修改圖使用的指標

    // 顧名思義,就是載入圖片的意思,它的使用方法為 IplImage* cvLoadImage("檔案名稱",參數);
    Orig_Image = cvLoadImage(FileName, CV_LOAD_IMAGE_COLOR);

    // 產生一個跟原始圖一樣大的空間記憶體拿來存放修改後的圖
    Modify_Image =  cvCreateImage(cvGetSize(Orig_Image), IPL_DEPTH_8U, 3);  // 第一個參數是 size , 第二參數是圖的深度 , 第三是  3 代表 rgb , 如果是 1 代表灰階 , 因為原始圖是彩色所以這邊是用3

    //如果讀入圖像失敗
    if (Orig_Image == NULL) {
        fprintf(stderr, "Can not load image %s\n", FileName);
        return -1;
    }

    //顯示原始圖像
    cvShowImage("Show Orig_Image", Orig_Image);

    // Orig_Image copy Modify_Image
    Modify_Image = cvCloneImage(Orig_Image);
    // 因為 Orig_Image = cvLoadImage 讀入圖後assign 給 Orig_Image 指標 , 指標是指向一維圖檔記憶體, 記憶體只有線性概念 ,
    // 所以 利用 RgbImage 把圖的一維記憶體經過邏輯轉換成二維方便操作 , 這邊操作是個小技巧會用就好因為這邊用到C++ template 比較複雜會用即可
    // IplImage* pImgColor = NULL; // 修改後圖的指標
    RgbImage BlockA(Modify_Image);

    // 印出圖寬高是多少
    printf("width=%d, height=%d\n", Orig_Image->width, Orig_Image->height);

    // 這時候 Modify_Image 內容還是原始圖內容未改變內容 , 下面對 100 X 100 區塊設定全白 
    for (i = 0; i < 100; ++i) {
        for (j = 0; j < 100; ++j) {
            BlockA[i][j].r = 255;
            BlockA[i][j].g = 255;
            BlockA[i][j].b = 255;
        }
    }

    //顯示圖像
    cvShowImage("Show Modify_Image", Modify_Image);
    //此函數等待按鍵，按鍵盤任意鍵就返回
    waitKey();
    return 0;
}
