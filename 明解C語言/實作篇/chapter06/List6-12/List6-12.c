/*
    對List 6-11做修正後的程式
*/

#include  <stdio.h>

#define para    10

void func(int __para);      /* 將para一邊遞減一邊做顯示 */

int main(void) {
    func(para);

    return (0);
}

void func(int no) {
    while (--no) {
        printf("%d\n", no);
    }
}

