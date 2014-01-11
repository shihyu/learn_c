/*****************************************
    檔名:ch13_08.cpp
    功能:建構函式的成員變數初始列應用
 *****************************************/

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
myclass::myclass(int a, int b): VarA(a), VarB(b) { //定義建構函式
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
