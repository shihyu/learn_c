#include <stdio.h>

int a = 0; // 全域變數初始化(data)
char *p1; // 全域變數未初始化(bss)

int main(void) {
    int b; // b=(stack)
    char s[] = "abc"; // s=(stack)
    char *p2; // p2=(stack)
    char *p3 = "123456"; // p3=(stack); "123456\0" text (rodata)
    static int c = 0; //c＝(data)
    p1 = (char *)malloc(10);
    p2 = (char *)malloc(20); // 配置 10 和 20 byte 在heap
    strcpy(p1, "123456"); // "123456\0" 放在text (rodata). 編譯器可能會将它與 p3 所指向的"123456\0"優化成一個地方。
    sleep(10000);
    return 0;
}
