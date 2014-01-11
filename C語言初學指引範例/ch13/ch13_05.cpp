/*********************************
    檔名:ch13_05.cpp
    功能:建構函式設定成員變數初值
 *********************************/

#include <stdlib.h>
#include <stdio.h>

class myclass {
public:
    int VarA;
    myclass();          //宣告建構函式
    void ShowVar();
private:
    int VarB;
};
myclass::myclass() {  //定義建構函式
    VarA = 0;
    VarB = 0;
    printf("成員資料已初始化\n");
}
void myclass::ShowVar() {
    printf("VarA=%d\n", VarA);
    printf("VarB=%d\n", VarB);
}

void main(void) {
    myclass X;
    X.ShowVar();
    /* system("pause"); */
}
