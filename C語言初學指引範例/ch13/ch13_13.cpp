/*******************************
    檔名:ch13_13.cpp
    功能:成員函式的覆載
 *******************************/

#include <stdlib.h>
#include <stdio.h>

class Vector2 {
public:
    double x, y;
    void Set(double, double);
};

class myclass {
public:
    int Sum(int, int);
    double Sum(double, double);
    int Sum(int, int, int);
    double Sum(double, double, double);
    Vector2 Sum(Vector2, Vector2);
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
Vector2 myclass::Sum(Vector2 a, Vector2 b) {
    Vector2 tempVector;
    tempVector.x = a.x + b.x;
    tempVector.y = a.y + b.y;
    return tempVector;
}

void Vector2::Set(double m, double n) {
    x = m;
    y = n;
}

void main(void) {
    myclass X;
    Vector2 i;
    i.Set(20, 40);
    Vector2 j;
    j.Set(15, 45);
    printf("Vector i=(%.0f,%.0f)\n", i.x, i.y);
    printf("Vector j=(%.0f,%.0f)\n", j.x, j.y);
    Vector2 k;
    k = X.Sum(i, j);
    printf("Vector k=(%.0f,%.0f)\n", k.x, k.y);
    /* system("pause"); */
}
