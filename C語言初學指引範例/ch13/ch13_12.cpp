/*******************************
    檔名:ch13_12.cpp
    功能:成員函式的覆載
 *******************************/

#include <stdlib.h>
#include <stdio.h>

class myclass {
public:
    int Sum(int, int);
    double Sum(double, double);
    int Sum(int, int, int);
    double Sum(double, double, double);
};
int myclass::Sum(int a, int b) {
    return a + b;
}
double myclass::Sum(double a, double b) {
    return a + b;
}
int myclass::Sum(int a, int b, int c) {
    return a + b + c;
}
double myclass::Sum(double a, double b, double c) {
    return a + b + c;
}

void main(void) {
    myclass X;
    printf("X.Sum(1,2)=%d\n", X.Sum(1, 2));
    printf("X.Sum(1.5,2.3)=%.1f\n", X.Sum(1.5, 2.3));
    printf("X.Sum(1,2,3)=%d\n", X.Sum(1, 2, 3));
    printf("X.Sum(1.5,2.3,3.7)=%.1f\n", X.Sum(1.5, 2.3, 3.7));
    /* system("pause"); */
}
