/**********************************
    檔名:ch13_11.cpp
    功能:觀察解建構函式的執行時機
 **********************************/

#include <stdlib.h>
#include <stdio.h>

class myclass {
public:
    myclass();           //宣告建構函式
    ~myclass();          //宣告解構函式
};
myclass::myclass() {  //定義建構函式
    printf("建構函式執行中..........\n");
}
myclass::~myclass() {  //定義解構函式
    printf("解構函式執行中..........\n");
}

void main(void) {
    printf("程式開始執行\n");
    printf("準備生成物件\n");
    myclass X;
    printf("物件生成完畢\n");
    printf("程式即將結束\n");
    /* system("pause"); */
}
