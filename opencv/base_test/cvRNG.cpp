#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    CvRNG rng;
    rng = cvRNG(cvGetTickCount());
    for(int i=0;i<100;i++)
    {
        printf("%d\n",cvRandInt(&rng));
    }
    printf("The Tick Frequency is %f\n",cvGetTickFrequency());
    return 0;
}
