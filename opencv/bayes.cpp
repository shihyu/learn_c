//openCV中贝叶斯分类器的API函数用法举例
//运行环境：winXP + VS2008 + openCV2.3.0
//
//
#include "ml.h"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc_c.h>
#include "iostream"
using namespace cv;
using namespace std;

//10个样本特征向量维数为12的训练样本集，第一列为该样本的类别标签
double inputArr[10][13] = {
    1, 0.708333, 1, 1, -0.320755, -0.105023, -1, 1, -0.419847, -1, -0.225806, 0, 1,
    -1, 0.583333, -1, 0.333333, -0.603774, 1, -1, 1, 0.358779, -1, -0.483871, 0, -1,
    1, 0.166667, 1, -0.333333, -0.433962, -0.383562, -1, -1, 0.0687023, -1, -0.903226, -1, -1,
    -1, 0.458333, 1, 1, -0.358491, -0.374429, -1, -1, -0.480916, 1, -0.935484, 0, -0.333333,
    -1, 0.875, -1, -0.333333, -0.509434, -0.347032, -1, 1, -0.236641, 1, -0.935484, -1, -0.333333,
    -1, 0.5, 1, 1, -0.509434, -0.767123, -1, -1, 0.0534351, -1, -0.870968, -1, -1,
    1, 0.125, 1, 0.333333, -0.320755, -0.406393, 1, 1, 0.0839695, 1, -0.806452, 0, -0.333333,
    1, 0.25, 1, 1, -0.698113, -0.484018, -1, 1, 0.0839695, 1, -0.612903, 0, -0.333333,
    1, 0.291667, 1, 1, -0.132075, -0.237443, -1, 1, 0.51145, -1, -0.612903, 0, 0.333333,
    1, 0.416667, -1, 1, 0.0566038, 0.283105, -1, 1, 0.267176, -1, 0.290323, 0, 1
};

//一个测试样本的特征向量
double testArr[] = {
    0.25, 1, 1, -0.226415, -0.506849, -1, -1, 0.374046, -1, -0.83871, 0, -1
};


int main(void) {
    Mat trainData(10, 12, CV_32FC1);//构建训练样本的特征向量

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            trainData.at<float>(i, j) = inputArr[i][j + 1];
        }
    }

    Mat trainResponse(10, 1, CV_32FC1);//构建训练样本的类别标签

    for (int i = 0; i < 10; i++) {
        trainResponse.at<float>(i, 0) = inputArr[i][0];
    }

    CvNormalBayesClassifier nbc;
    bool trainFlag = nbc.train(trainData, trainResponse);//进行贝叶斯分类器训练

    if (trainFlag) {
        cout << "train over..." << endl;
        nbc.save("normalBayes.txt");
    } else {
        cout << "train error..." << endl;
        system("pause");
        exit(-1);
    }


    CvNormalBayesClassifier testNbc;
    testNbc.load("normalBayes.txt");

    Mat testSample(1, 12, CV_32FC1);//构建测试样本

    for (int i = 0; i < 12; i++) {
        testSample.at<float>(0, i) = testArr[i];
    }

    float flag = testNbc.predict(testSample);//进行测试
    cout << "flag = " << flag << endl;

    return 0;
}
