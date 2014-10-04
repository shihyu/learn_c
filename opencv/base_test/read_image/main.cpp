#include "opencv.h"
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	const char* imagename = "lena.jpg";

	//從文件中讀入圖像
	Mat img = imread(imagename);

	//如果讀入圖像失敗
	if(img.empty())
	{
		fprintf(stderr, "Can not load image %s\n", imagename);
		return -1;
	}

	//顯示圖像
	imshow("image", img);

	//此函數等待按鍵，按鍵盤任意鍵就返回
	waitKey();

	return 0;
}
