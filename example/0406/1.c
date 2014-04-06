#include <stdio.h>
#include <stdlib.h>

#define LEN 6 

/* stdlib.h 定義一個常數 RAND_MAX，RAND_MAX 一般是 32767
 * rand() 會回傳 0 ~ 32767 間的一個整數，假設為 r，則 0 <= r <= 32767
 * 避免每次 rand() 回傳的整數都一樣，可用 srand() 設定不同的亂數種子
 * */

int main(int argc, char *argv[])
{
    int data[LEN];
    int i;

    srand(time(NULL)); // 設定不同的亂數種子

    // int r = rand();  例如透過rand函數亂數產生數值給r變數

    for (i = 0; i < LEN; ++i) {
        // for 裡面利用rand() 產生6個數字1~49範圍的數字,存到data 陣列
    }

    // 印出data 6個數字
    for (i = 0; i < LEN; ++i) {

    }

    return 0;
}
