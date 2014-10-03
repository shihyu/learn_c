#include "ml.h"
#include "highgui.h"
// g++ -ggdb `pkg-config --cflags opencv` KNN.cpp -o KNN `pkg-config --libs opencv`

int main(int argc, char** argv) {
    const int K = 10;
    int i, j, k, accuracy;
    float response;
    // Step 0: 建立 100 組 (x,y) 資料的陣列 與 存放標準答案的陣列 
    int train_sample_count = 100;

    CvRNG rng_state = cvRNG(-1);
    CvMat* trainData = cvCreateMat(train_sample_count, 2, CV_32FC1);
    CvMat* trainClasses = cvCreateMat(train_sample_count, 1, CV_32FC1);
    IplImage* img = cvCreateImage(cvSize(500, 500), 8, 3);
    float _sample[2];
    CvMat sample = cvMat(1, 2, CV_32FC1, _sample);
    cvZero(img);

    CvMat trainData1, trainData2, trainClasses1, trainClasses2;

    // form the training samples
    cvGetRows(trainData, &trainData1, 0, train_sample_count / 2);
    cvRandArr(&rng_state, &trainData1, CV_RAND_NORMAL, cvScalar(200, 200), cvScalar(50, 50));

    cvGetRows(trainData, &trainData2, train_sample_count / 2, train_sample_count);
    cvRandArr(&rng_state, &trainData2, CV_RAND_NORMAL, cvScalar(300, 300), cvScalar(50, 50));

    cvGetRows(trainClasses, &trainClasses1, 0, train_sample_count / 2);
    cvSet(&trainClasses1, cvScalar(1));

    cvGetRows(trainClasses, &trainClasses2, train_sample_count / 2, train_sample_count);
    cvSet(&trainClasses2, cvScalar(2));

    // 如何把 training set 丟給 KNN 物件學習?
    // learn classifier
    CvKNearest knn(trainData, trainClasses, 0, false, K);
    CvMat* nearests = cvCreateMat(1, K, CV_32FC1);

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            sample.data.fl[0] = (float)j;
            sample.data.fl[1] = (float)i;

            // estimate the response and get the neighbors' labels
            response = knn.find_nearest(&sample, K, 0, 0, nearests, 0);

            // compute the number of neighbors representing the majority
            for (k = 0, accuracy = 0; k < K; k++) {
                if (nearests->data.fl[k] == response) {
                    accuracy++;
                }
            }

            // highlight the pixel depending on the accuracy (or confidence)
            cvSet2D(img, i, j, response == 1 ?
                    (accuracy > 5 ? CV_RGB(180, 0, 0) : CV_RGB(180, 120, 0)) :
                    (accuracy > 5 ? CV_RGB(0, 180, 0) : CV_RGB(120, 120, 0)));
        }
    }

    // display the original training samples
    for (i = 0; i < train_sample_count / 2; i++) {
        CvPoint pt;
        pt.x = cvRound(trainData1.data.fl[i * 2]);
        pt.y = cvRound(trainData1.data.fl[i * 2 + 1]);
        cvCircle(img, pt, 2, CV_RGB(255, 0, 0), CV_FILLED);
        pt.x = cvRound(trainData2.data.fl[i * 2]);
        pt.y = cvRound(trainData2.data.fl[i * 2 + 1]);
        cvCircle(img, pt, 2, CV_RGB(0, 255, 0), CV_FILLED);
    }

    cvNamedWindow("classifier result", 1);
    cvShowImage("classifier result", img);
    cvWaitKey(0);

    cvReleaseMat(&trainClasses);
    cvReleaseMat(&trainData);
    return 0;
}
