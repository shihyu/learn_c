/*********************************
    檔名:ch13_06.cpp
    功能:建構函式的引數應用
 *********************************/

#include <stdlib.h>
#include <stdio.h>

class myclass {
public:
    int VarA;
    myclass(int, int);         //宣告建構函式
    void ShowVar();
private:
    int VarB;
};
myclass::myclass(int a, int b) { //定義建構函式
    VarA = a;
    VarB = a + b;
}
void myclass::ShowVar() {
    printf("VarA=%d\n", VarA);
    printf("VarB=%d\n", VarB);
}

void main(void) {
    myclass X(3, 10);
    myclass Y(5, 40);
    printf("物件X\n");
    X.ShowVar();
    printf("物件Y\n");
    Y.ShowVar();
    /* system("pause"); */
}
