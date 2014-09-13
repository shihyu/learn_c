#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc_c.h>

// build command
// g++ -ggdb `pkg-config --cflags opencv` CannyEdge.cpp -o CannyEdge `pkg-config --libs opencv`

int edgeThresh = 50;

int main() {
    IplImage* pImg = cvLoadImage("lena.jpg");

    if (pImg) {
        IplImage* pImgGray =  cvCreateImage(cvGetSize(pImg),
                                            IPL_DEPTH_8U, 1);
        IplImage* pImgEdge =  cvCreateImage(cvGetSize(pImg),
                                            IPL_DEPTH_8U, 1);
        //建立兩張空白影像儲存灰階和邊緣影像

        cvCvtColor(pImg, pImgGray, CV_BGR2GRAY);
        //轉成灰階影像"CV_BGR2GRAY"

        cvCanny(pImgGray, pImgEdge, edgeThresh, edgeThresh * 3, 3);
        //edgeThresh = 控制邊緣連接門檻(數值越大代表對比越大)
        //edgeThresh*3 = 控制初始影像的分割門檻(數值越大代表對比越大)
        //3 = Sobel運算元

        cvShowImage("image", pImg);
        cvShowImage("Canny", pImgEdge);
        cvReleaseImage(&pImgGray);
        cvReleaseImage(&pImgEdge);
    }

    cvWaitKey(0);
    cvReleaseImage(&pImg);
}

